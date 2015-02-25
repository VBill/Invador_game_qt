#include "shot.h"

#include <QPainter>
#include <QRect>

#define VELOCITY 40.0

Shot::Shot(int x)
{
  this->x=x;
  shot_time=0;
  to_del=false;
}

void Shot::paintShot(QPainter *p){
  if((shot_time/6)%2==0)
	p->setBrush(Qt::yellow);
  else
	p->setBrush(Qt::red);
  p->setPen(Qt::NoPen);
  p->drawRect( getShotRect() );
}

QRect Shot::getShotRect(){
  QRect this_shot(x, 340-shot_time, 6, 6);
  return this_shot;
}

void Shot::moveSelf(){
  shot_time+=6;
}
