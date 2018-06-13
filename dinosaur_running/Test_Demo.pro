#-------------------------------------------------
#
# Project created by QtCreator 2018-06-10T16:03:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_Demo
TEMPLATE = app


SOURCES += main.cpp \
    obstacle.cpp \
    space.cpp \
    dinosaur.cpp \
    Randomizer.cpp

HEADERS  += \
    obstacle.h \
    space.h \
    dinosaur.h \
    Randomizer.h \
    global.h

FORMS    += gamewidget.ui

RESOURCES += \
    resource.qrc
