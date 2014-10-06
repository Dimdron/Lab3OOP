#include "Window.h"


Window::Window(int w, int h)
    :ResizableWindow(w, h)
{
}

Window::Window(Window& window)
    :Window(window.getWidth(), window.getHeight())
{
    name = new string(window.getName());
    x = window.getX();
    y = window.getY();
}

Window::~Window()
{
}

std::string Window::getName()
{
    return name;
}

void Window::setName(std::string name)
{
    this->name = name;
}

int Window::getX()
{
    return x;
}

int Window::getY()
{
    return y;
}

void Window::setX(int x)
{
    this->x = x;
}

void Window::setY(int y)
{
    this->y = y;
}

char* Window::getCanvas()
{
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

    return window;
}

void Window::move(int dx, int dy) {
    x += dx;
    y += dy;
}

Window& Window::operator= (const Window& window) {
    if (&window == this) return *this;
    if (null == name) delete name;
    if (null != window.name)
        name = new string(window.name);
    else
        name = null;

    x = window.x;
    y = window.y;
    setWidth(window.getWidth());
    setHeight(window.getHeight());
}
