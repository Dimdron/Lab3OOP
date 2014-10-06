QT       -= core gui

TARGET = WindowsLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += window.cpp \
    resizablewindow.cpp

HEADERS += window.h \
    resizablewindow.h

DESTDIR = ../build
