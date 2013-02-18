#-------------------------------------------------
#
# Project created by QtCreator 2013-02-18T11:26:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UnRedo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    history.cpp \
    textwidget.cpp

HEADERS  += mainwindow.h \
    command.h \
    history.h \
    textwidget.h

FORMS    += mainwindow.ui \
    textwidget.ui
