#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "resizablewindow.h"

class MainWindow: public ResizableWindow
{
public:
    typedef std::vector<ResizableWindow*> children_container;

    MainWindow();
    MainWindow(int xpos, int ypos, const std::string &windowName,
               int windowWidth, int windowHeight);
    MainWindow(const MainWindow &window);
    ~MainWindow();

    void draw();
    const children_container &getChildren() const;

    MainWindow& operator<<(ResizableWindow *child);
    ResizableWindow *operator[] (int i);

    static const int minWidth = 15;
    static const int minHeight = 8;
    static const int maxWidth = 79;
    static const int maxHeight = 25;

protected:
    children_container subwindows;
    void drawChildWindow(Canvas &values, ResizableWindow *child);
};

#endif // MAINWINDOW_H
