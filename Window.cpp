#include "window.h"


Window::Window()
    : x(0), y(0), name()
{
}

Window::Window(int xpos, int ypos, std::string windowName)
    : x(xpos), y(ypos), name(windowName)
{
}

Window::Window(const Window& window) :
    x(window.x), y(window.y), name(window.name)
{
}

Window::~Window()
{
}

std::string Window::getName() const
{
    return name;
}

int Window::getX() const
{
    return x;
}

int Window::getY() const
{
    return y;
}

void Window::setX(int xpos)
{
    x = xpos;
}

void Window::setY(int ypos)
{
    y = ypos;
}

void Window::setPosition(int xpos, int ypos)
{
    x = xpos;
    y = ypos;
}

void Window::setName(const std::string &newName)
{
    name = newName;
}

void Window::move(int dx, int dy)
{
    x += dx;
    y += dy;
}
