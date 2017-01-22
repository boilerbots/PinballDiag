#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T16:36:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PinballDiag
TEMPLATE = app
CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    hw.cpp \
    test.cpp \
    test_thread.cpp

HEADERS  += mainwindow.h \
    hw.h \
    test.h \
    test_thread.h

FORMS    += mainwindow.ui

DISTFILES += \
    LICENSE.txt
