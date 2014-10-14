#ifndef MAINWINDOWPROXY_H
#define MAINWINDOWPROXY_H

#include "mainwindow.h"

class MainWindowProxy1
{
public:
    MainWindowProxy1(MainWindow *mainWnd) : mainWindow(mainWnd) {}
    ~MainWindowProxy1() {}

    MainWindow *operator->()
    {
        return mainWindow;
    }

private:
    MainWindow *mainWindow;
};

class MainWindowProxy2
{
public:
    MainWindowProxy2(MainWindowProxy1 *proxyPointer) : proxy(proxyPointer) {}
    ~MainWindowProxy2() {}

    MainWindowProxy1 &operator->()
    {
        return *proxy;
    }

private:
    MainWindowProxy1 *proxy;
};

#endif // MAINWINDOWPROXY_H
