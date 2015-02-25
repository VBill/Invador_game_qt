#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "judgement.h"

#include <QShortcut>
#include <QKeySequence>
#include <QMessageBox>

#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);
}

MainWindow::~MainWindow(){
  delete ui;
}

void MainWindow::setUserUI(){
  connectUserSlots();

  //change widget color
  //must check autofillbackground true
  ui->battle_widget->setPalette( QPalette (QColor(0, 0, 200) ) );
  ui->lcdScore->setPalette(QPalette (QColor(0, 0, 0) ));
}

void MainWindow::connectUserSlots(){
  //add buttons slots
  connect(ui->btn_quit, SIGNAL(clicked()), qApp, SLOT(quit()));

  //add shortcuts
  QShortcut *left=new QShortcut(QKeySequence(Qt::Key_A), this);
  connect(left, SIGNAL(activated()), this,
		  SLOT(on_btn_left_clicked()));
  QShortcut *right=new QShortcut(QKeySequence(Qt::Key_D), this);
  connect(right, SIGNAL(activated()), this,
		  SLOT(on_btn_right_clicked()));
  QShortcut *shoot=new QShortcut(QKeySequence(Qt::Key_Space), this);
  connect(shoot, SIGNAL(activated()), this,
		  SLOT(on_btn_shoot_clicked()));

  //add LCD
  connect(ui->battle_widget, SIGNAL(hit()),
		  this, SLOT(hit()));
}

void MainWindow::on_btn_new_game_clicked()
{
  ui->lcdScore->display(0);
  ui->battle_widget->restartGame();
  ui->battle_widget->newTarget();
}

void MainWindow::on_btn_quit_clicked()
{
  //do nothing
}

void MainWindow::on_btn_shoot_clicked()
{
  //fire
  if( ui->battle_widget->game_over )
	return;
  ui->battle_widget->shoot();
}

void MainWindow::on_btn_left_clicked()
{
	ui->battle_widget->moveLeft();
}

void MainWindow::on_btn_right_clicked()
{
	ui->battle_widget->moveRight();
}

void MainWindow::on_btn_help_clicked()
{
  //show help message
  QMessageBox msg;
  msg.setWindowTitle("Help");
  msg.setText("A: move left\t\nD: move right\t\nSpace: fire"
			  "\n10 targets and 10 scores, enjoy it!");
  msg.exec();
}

void MainWindow::hit(){
  ui->lcdScore->display(ui->lcdScore->intValue()+1);
}
