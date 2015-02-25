#ifndef CANNON_H
#define CANNON_H

#include <QRect>

class Widget;
class QPainter;
class Judgement;

class Cannon
{
	QRect cannon;
  public:
	Cannon();

	void setX(bool increase);
	const QRect& getCannonRect() const;
	void paintCannon(Judgement* widget, QPainter *p);
};

#endif // CANNON_H
