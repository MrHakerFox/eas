#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T08:19:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EASCC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cr/easCore.cpp

HEADERS  += mainwindow.h \
    cr/easCore.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    eas.qrc
