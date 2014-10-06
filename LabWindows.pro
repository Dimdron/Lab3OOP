QT       += core

QT       -= gui

TARGET = LabWindows
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    resizablewindow.cpp \
    window.cpp

HEADERS += \
    mainwindow.h \
    menu.h \
    resizablewindow.h \
    window.h
