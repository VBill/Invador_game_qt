#ifndef TARGET_H
#define TARGET_H

#include <QRect>
#include <QPoint>

class QPainter;

class Target
{
	QPoint target;
	int height;
  public:
	bool hidden;
	Target();

	QRect getTargetRect();
	void paintTarget(QPainter *p);
	void setXY(int x, int y);
	void moveTarget();
};

#endif // TARGET_H
