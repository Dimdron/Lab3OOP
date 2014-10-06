QT       -= core gui

TARGET = LabWindows
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

INCLUDEPATH += WindowsLib

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    menu.cpp

HEADERS += \
    menu.h \
    mainwindow.h

LIBS += -Lbuild/ -lWindowsLib
