#-------------------------------------------------
#
# Project created by QtCreator 2016-01-22T15:25:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkyGUI
TEMPLATE = app


SOURCES += main.cpp\
        networkwindow.cpp \
    ../Network.cpp \
    ../Person.cpp \
    ../TestSuit.cpp

HEADERS  += networkwindow.h \
    ../Network.h \
    ../Person.h \
    ../TestSuit.h

FORMS    += networkwindow.ui