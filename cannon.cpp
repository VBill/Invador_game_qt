#include "cannon.h"

#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include "judgement.h"

Cannon::Cannon()
{
  //256 is half judgement size
  cannon=QRect(256-35, 328, 140, 70);
  //cannon=QRect(512-35, 328, 140, 70);
}

void Cannon::setX(bool increase){
  int xx=cannon.x();
  if(increase)
	xx+=4;
  else
	xx-=4;
  if(xx<-35 || xx>478)
	return;
  cannon.setX(xx);//move left or right
}

const QRect& Cannon::getCannonRect() const{
  return cannon;
}

void Cannon::paintCannon(Judgement* widget, QPainter *p){
  //QPixmap pix(cannon.size());//a paint device of cannon size, not initialized
  QPixmap pix( QSize(140, 70) );
  pix.fill(widget, cannon.topLeft() );//call fill to init, fill background color

  QPainter tmp( &pix );
  tmp.setBrush(Qt::gray);
  tmp.setPen( Qt::NoPen);

  tmp.translate(0, pix.height()-1 );//use  coordinate system
  tmp.drawPie( QRect(0, -35, 70, 70) , 0, 180*16);
  tmp.translate(35-5,0);
  tmp.rotate(-90.0);
  tmp.drawRect( QRect(33, -4, 15, 16) );
  tmp.end();

  p->drawPixmap( cannon.topLeft(), pix );
}
