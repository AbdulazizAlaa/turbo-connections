#-------------------------------------------------
#
# Project created by QtCreator 2016-01-22T15:25:17
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkyGUI
TEMPLATE = app


SOURCES += main.cpp\
        networkwindow.cpp \
    openglwidget.cpp \
    visualizingwindow.cpp \
    node.cpp \
    link.cpp \
    network.cpp \
    person.cpp

HEADERS  += networkwindow.h \
    openglwidget.h \
    visualizingwindow.h \
    node.h \
    link.h \
    network.h \
    person.h

FORMS    += networkwindow.ui \
    visualizingwindow.ui
