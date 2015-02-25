#include "target.h"

#include <QPainter>
#include <QPoint>

Target::Target()
{
  target=QPoint();
  hidden=false;
}

QRect Target::getTargetRect(){
  QRect r(0, 0, 20, 10);
  r.moveCenter( QPoint(20 + target.x(), 15 + target.y()) );
  return r;
}

void Target::paintTarget(QPainter *p){
  p->setBrush( Qt::red );
  p->setPen( Qt::black );
  p->drawRect( getTargetRect() );
}

void Target::setXY(int x, int y){
  target.setX(x);
  target.setY(y);
}

void Target::moveTarget(){
  int yy=target.y()+1;
  target.setY( yy );
}
