#include "MainWindow.h"
#include "Menu.h"
int main(int argc, char *argv[])
{
    MainWindow *myWindow = new MainWindow(35, 20);

    Window *w1 = new Window(5, 5);
    w1->setX(3);
    w1->setY(4);
    *myWindow<<w1;
    bool continueFlag = true;
    Menu* menu = new Menu(myWindow);
    while(continueFlag)
        continueFlag = menu->show();
    return 0;
}
