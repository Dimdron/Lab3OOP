#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "resizablewindow.h"

class MainWindow: public ResizableWindow
{
public:
    typedef std::vector<Window> children_container;

    MainWindow();
    MainWindow(int xpos, int ypos, const std::string &windowName,
               int windowWidth, int windowHeight);
    MainWindow(const MainWindow &window);
    ~MainWindow();

    void draw();
    children_container &getChildren();

    MainWindow& operator<<(Window* child);
    Window& operator[] (int i);

    static const int minWidth = 15;
    static const int minHeight = 8;
    static const int maxWidth = 79;
    static const int maxHeight = 25;

protected:
    children_container subwindows;
    void addWindow(char* mainWindow, Window* child);
};

#endif // MAINWINDOW_H
