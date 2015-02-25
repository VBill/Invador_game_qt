#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setUserUI();
    w.setGeometry( 100, 100, 500, 355 );
    w.show();

    return a.exec();
}
