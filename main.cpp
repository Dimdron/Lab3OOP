#include "menu.h"
#include "canvas.h"
#include <iostream>

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

void testCase2()
{
    int width = 10;
    int height = 10;
    ResizableWindow window(0, 0, "window", width, height);
    Canvas canvas = window.getCanvas();
    canvas(5, 5) = 'O';
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            std::cout << *(canvas(i, j));
        std::cout << std::endl;
    }
}

int main()
{
//    testCase1();
    testCase2();
//    Menu menu;
//    menu.start();
    return 0;
}
