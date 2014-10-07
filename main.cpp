#include "menu.h"

void testCase1()
{
    MainWindow *mainWindow = new MainWindow(0, 0, "main", 35, 20);
    ResizableWindow *w1 = new ResizableWindow(2, 2, "w1", 5, 5);
    w1->setX(3);
    w1->setY(4);
    *mainWindow << w1;
    mainWindow->draw();
    delete mainWindow;
}

int main()
{
//    testCase1();
    Menu menu;
    menu.start();
    return 0;
}
