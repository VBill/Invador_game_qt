#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "judgement.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUserUI();

public slots:
	void hit();

private slots:
    void on_btn_new_game_clicked();

    void on_btn_quit_clicked();

	void on_btn_shoot_clicked();

	void on_btn_left_clicked();

	void on_btn_right_clicked();

	void on_btn_help_clicked();

  private:
    Ui::MainWindow *ui;
    Judgement *judge;

    void connectUserSlots();
};

#endif // MAINWINDOW_H
