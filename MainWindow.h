#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ResizableWindow.h"
#include "Window.h"
#include <list>
class MainWindow: public Window
{
    static const int MIN_WIDTH = 15;
    static const int MAX_WIDTH = 79;
    static const int MIN_HEIGHT = 8;
    static const int MAX_HEIGHT = 25;
private:
    std::list<Window>* subwindows;
    void addWindow(char* mainWindow, Window* child);
public:
	MainWindow();
    MainWindow(int width, int height);
	~MainWindow();

	void draw();
    std::list<Window>* getChildren();

    MainWindow& operator<<(Window* child);
    Window& operator[] (int i);
};

#endif // MAINWINDOW_H
