#-------------------------------------------------
#
# Project created by QtCreator 2013-02-18T11:24:56
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_unredotest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ../UnRedo/history.cpp \
    testcommand.cpp \
    main.cpp \
    testcommandtest.cpp \
    historytest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    testcommand.h \
    AutoTest.h \
    testcommandtest.h \
    historytest.h
