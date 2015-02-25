#-------------------------------------------------
#
# Project created by QtCreator 2015-02-16T22:48:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Invador
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    judgement.cpp \
    shot.cpp \
    cannon.cpp \
    target.cpp \
    gameboard.cpp

HEADERS  += mainwindow.h \
    judgement.h \
    shot.h \
    cannon.h \
    target.h \
    gameboard.h

FORMS    += mainwindow.ui
