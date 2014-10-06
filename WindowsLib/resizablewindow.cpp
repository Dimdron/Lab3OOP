#include "resizablewindow.h"

ResizableWindow::ResizableWindow()
    : Window(), width(0), height(0)
{
}

ResizableWindow::ResizableWindow(int xpos, int ypos, const std::string &windowName,
                                 int windowWidth, int windowHeight)
    : Window(xpos, ypos, windowName), width(windowWidth), height(windowHeight)
{
}

ResizableWindow::ResizableWindow(const ResizableWindow &window)
    : Window(window), width(window.width), height(window.height)
{
}

ResizableWindow::~ResizableWindow()
{
}

int ResizableWindow::getWidth() const
{
    return width;
}

int ResizableWindow::getHeight() const
{
    return height;
}

void ResizableWindow::changeSize(int dw, int dh) {
    width += dw;
    height += dh;
}

void ResizableWindow::setWidth(int windowWidth)
{
    width = windowWidth;
}

void ResizableWindow::setHeight(int windowHeight)
{
    height = windowHeight;
}

ResizableWindow::canvas_type ResizableWindow::getCanvas() const
{
    return canvas_type(width * height);/*
    const int h_ = getHeight();
    const int w_ = getWidth();
    char* window = new char[h_*w_];

    for (int h = 0; h < h_; h++)
        for (int w = 0; w < w_; w++)
            if (0 == h || h_ - 1 == h)
                *(window + h*w_ + w) = '*';
            else
                if (0 == w || w_ - 1 == w)
                    *(window + h*w_ + w) = '*';
                else
                    *(window + h*w_ + w) = ' ';

    return window;*/
}
