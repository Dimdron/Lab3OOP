#include "ResizableWindow.h"


ResizableWindow::ResizableWindow(int w, int h)
{
    width = w;
    height = h;
}


ResizableWindow::~ResizableWindow()
{
}

int ResizableWindow::getHeight()
{
    return height;
}

int ResizableWindow::getWidth()
{
    return width;
}

void ResizableWindow::changeSize(int dw, int dh) {
    width += dw;
    height += dh;
}

void ResizableWindow::setHeight(int height)
{
    if (height == this->height) return;
    this->height = height;
    //onChangedSize(width, height);
}

void ResizableWindow::setWidth(int width)
{
    if (width == this->width) return;
    this->width = width;
    //onChangedSize(width, height);
}
