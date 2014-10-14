#include "menu.h"
#include "canvas.h"
#include "mainwindowproxy.h"
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

void testCase3()
{
    MainWindow mainWindow(0, 0, "window", 10, 5);
    MainWindowProxy1 proxy1(&mainWindow);
    MainWindowProxy2 proxy2(&proxy1);

    proxy2->draw();
}

int main()
{
//    testCase1();
//    testCase2();
    testCase3();
//    Menu menu;
//    menu.start();
    return 0;
}
