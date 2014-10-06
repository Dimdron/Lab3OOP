#ifndef MENU_H
#define MENU_H
#include "MainWindow.h"

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
    Menu(MainWindow w);
    void show();
};

#endif // MENU_H
