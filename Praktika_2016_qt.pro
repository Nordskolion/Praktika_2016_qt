#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T22:30:25
#
#-------------------------------------------------

QT       += core gui
CONFIG += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Praktika_2016_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ClassifyDocum.cpp \
    NormalizeDocum.cpp

HEADERS  += mainwindow.h \
    ClassifyDocum.h \
    NormalizeDocum.h

FORMS    += mainwindow.ui
