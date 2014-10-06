#pragma once
#include "mainwindow.h"

class Menu
{
private:
    MainWindow window;

    void mainMenu();
    void changeSize();
    void changePosition();
    void addWindow();
    Window* findWindow(std::string name);
    Window* chooseWindow();

public:
    Menu(MainWindow &newWindow);
    void show();
};
