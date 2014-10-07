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

//    Window *w1 = new Window(5, 5);
//    w1->setX(3);
//    w1->setY(4);
//    *myWindow<<w1;
//    bool continueFlag = true;
//    Menu* menu = new Menu(myWindow);
int main()
{
//    testCase1();
    return 0;
}
