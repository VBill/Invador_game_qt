#ifndef JUDGEMENT_H
#define JUDGEMENT_H

#include <QWidget>

#include <vector>
#include <list>

#include "target.h"
#include "shot.h"
#include "cannon.h"

class QTimer;
class QRect;

class Judgement : public QWidget
{
  Q_OBJECT
public:
  bool game_over;

  explicit Judgement(QWidget *parent = 0);
  bool isShooting() const;

public slots:
  void shoot();
  void newTarget();
  void setGameOver();
  void restartGame();
  void moveLeft();
  void moveRight();

private slots:
  void moveShotsAndTargets();

signals:
  void hit();

protected:
  void paintEvent(QPaintEvent *e);

private:
  QTimer *moveTimer;

  std::vector<Target> targets;
  std::vector<Shot> shots;
  Cannon* cannon;

  QRect judge;

  int timerCount;
  int score;

  bool can_shoot;
};

#endif // JUDGEMENT_H
