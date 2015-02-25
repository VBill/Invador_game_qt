#include "judgement.h"
#include "target.h"

#include <QTimer>
#include <QDateTime>
#include <QPainter>
#include <QPaintEvent>

#include <vector>
#include <string>
#include <cstdlib>

#define VELOCITY 40.0
#define MAX_TAR 10

using namespace std;

Judgement::Judgement(QWidget *parent) :
  QWidget(parent){
  //create timer and link slots and signals
  moveTimer=new QTimer(this);
  connect(moveTimer, SIGNAL(timeout()),
		  this , SLOT(moveShotsAndTargets()) );

  score=0;
  can_shoot=true;
  game_over=false;
  cannon=new Cannon();
  judge=QRect(0, 328, 512, 70);
}

bool Judgement::isShooting() const{
  return moveTimer->isActive();
}

void Judgement::shoot(){
  shots.push_back( Shot(cannon->getCannonRect().x()
						+ 32) );
}

void Judgement::newTarget(){
  static bool first_game=true;
  if(first_game){
	first_game=false;
	QTime midnight(0, 0, 0);
	srand( midnight.secsTo( QTime::currentTime() ) );
  }
  //build target
  targets.clear();
  for(int i=0; i<MAX_TAR; i++){
	targets.push_back( Target() );
	targets[i].setXY( rand()%450,
					  rand()%100);
  }
  repaint();
}

void Judgement::setGameOver(){
  if( game_over )return;
  if( isShooting())
	moveTimer->stop();
  game_over=true;
  repaint();
}

void Judgement::restartGame(){
  if(isShooting())
	moveTimer->stop();
  game_over=false;
  shots.clear();
  targets.clear();
  score=0;
  repaint();

  moveTimer->start(50);
}

void Judgement::moveLeft(){
  cannon->setX(false);
  repaint();
}

void Judgement::moveRight(){
  cannon->setX(true);
  repaint();
}

void Judgement::moveShotsAndTargets(){
  vector<Shot>::iterator shot_pt;
  for(shot_pt=shots.begin(); shot_pt!=shots.end() && shots.size()>0; ++shot_pt){
	shot_pt->moveSelf();

	vector<Target>::iterator tar_pt;
	for(tar_pt=targets.begin(); tar_pt!=targets.end() && (int)targets.size()>0; ++tar_pt){
	  if(shot_pt->getShotRect().intersects(tar_pt->getTargetRect())){
		targets.erase(tar_pt);//max tar 15, no need to remove
		shot_pt->to_del=true;
		score++;
		emit hit();
		break;
	  }
	}

	if(shot_pt->getShotRect().y()<0 || shot_pt->to_del){
	  //remove this shot and continue
	  shot_pt=shots.erase(shot_pt);
	  --shot_pt;
	}
  }

  for(int j=0; j<(int)targets.size(); ++j){
	targets[j].moveTarget();
	if(targets[j].getTargetRect().intersects(judge))
	  game_over=true;
  }

  if(score==MAX_TAR)
	game_over=true;

  repaint();
}

void Judgement::paintEvent(QPaintEvent *e){
  QRect updateR = e->rect();
  QPainter p( this );

  if(game_over){
	string ss("Game over");
	p.setPen(Qt::black);
	p.setFont( QFont( "Courier", 36, QFont::Bold ) );
	if(score!=MAX_TAR)
	  p.drawText( rect(), Qt::AlignCenter, ss.c_str() );
	else
	  p.drawText( rect(), Qt::AlignCenter, "You win!");
  }

  if( updateR.intersects( cannon->getCannonRect() ) )
	cannon->paintCannon( this, &p);

  if( isShooting() ){
	for(int i=0; i<(int)shots.size(); ++i){
	  if(updateR.intersects(shots[i].getShotRect())){
		shots[i].paintShot( &p );
	  }
	}//end for
  }//end if

  if( !game_over ){
	for(int i=0; i<(int)targets.size(); i++){
	  if(updateR.intersects( targets[i].getTargetRect())
		 && !targets[i].hidden){
		targets[i].paintTarget( &p );
	  }
	}
  }
}
