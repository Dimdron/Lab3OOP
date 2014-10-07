#ifndef MENU_H
#define MENU_H

#include "mainwindow.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void start();

private:
    MainWindow mainWindow;

    void mainMenu();
    void changeSize();
    void changePosition();
    void addWindow();

    ResizableWindow *findWindow(const std::string &name);
    ResizableWindow *chooseWindow();
};

#endif // MENU_H
