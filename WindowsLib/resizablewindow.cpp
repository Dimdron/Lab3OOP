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

Canvas ResizableWindow::getCanvas() const
{
    Canvas values(width, height);

    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            if (h == 0 || h == height - 1)
            {
                values[(h * width) + w] = '*';
            }
            else
            {
                if (w == 0 || w == width - 1)
                {
                    values[(h * width) + w] = '*';
                }
                else
                {
                    values[(h * width) + w] = ' ';
                }
            }
        }
    }

    return values;
}
