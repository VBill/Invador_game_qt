#ifndef SHOT_H
#define SHOT_H

class QRect;
class QPainter;

class Shot
{
	int shot_time;
	int x;
  public:
	bool to_del;
	Shot(int x);

	void paintShot( QPainter * );
	QRect getShotRect();
	void moveSelf();
};

#endif // SHOT_H
