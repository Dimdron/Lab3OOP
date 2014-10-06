#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include "Window.h"

class SubWindow : public Window
{
private:
    Window parent;
public:
    SubWindow();
    SubWindow(int w, int h);

    void getCanvas();
};

#endif // SUBWINDOW_H
