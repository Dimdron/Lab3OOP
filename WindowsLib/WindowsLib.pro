QT       -= core gui

TARGET = WindowsLib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += window.cpp \
    resizablewindow.cpp

HEADERS += window.h \
    resizablewindow.h

DESTDIR = ../build
