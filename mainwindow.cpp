#include "mainwindow.h"

MainWindow::MainWindow()
    : ResizableWindow()
{
    setWidth(minWidth);
    setHeight(minHeight);
}

MainWindow::MainWindow(int xpos, int ypos, const std::string &windowName,
                       int windowWidth, int windowHeight)
    : ResizableWindow(xpos, ypos, windowName, windowWidth, windowHeight)
{
}

MainWindow::MainWindow(const MainWindow &window)
    : ResizableWindow(window)
{
    subwindows = window.subwindows;
}

MainWindow::~MainWindow()
{
}

void MainWindow::draw()
{
    Canvas values = getCanvas();

    for(auto i = subwindows.begin(); i != subwindows.end(); ++i)
        drawChildWindow(values, *i);

    for (int h = 0; h  < height; ++h)
    {
        for (int w = 0; w < width; ++w)
            putchar(values[(h * width) + w]);
        putchar('\n');
    }
}

const MainWindow::children_container &MainWindow::getChildren() const
{
    return subwindows;
}

void MainWindow::drawChildWindow(Canvas &values, ResizableWindow *child)
{
    auto childCanvas = child->getCanvas();
    const int childHeight = child->getHeight();
    const int childWidth = child->getWidth();
    const int childX = child->getX();
    const int childY = child->getY();
    int i_end = (childX + childWidth) < width ? childX + childWidth : width;
    int j_end = (childY + childHeight) < height ? childY + childHeight : height;
    i_end += width * childY;
    int x_tmp = 0;
    int y_tmp = 0;
    for (int j = childY; j < j_end; j++) // height
    {
        x_tmp = childWidth * y_tmp;
        for(int i = width * j + childX; i < i_end; i++)
        {
            values[i] = childCanvas[x_tmp];
            ++x_tmp;
        }
        i_end += width;
        ++y_tmp;
    }
}

MainWindow& MainWindow::operator <<(ResizableWindow* child)
{
    subwindows.push_back(child);
    return *this;
}

ResizableWindow *MainWindow::operator[] (int i)
{
    return subwindows.at(i);
}
