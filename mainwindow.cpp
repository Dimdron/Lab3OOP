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
    auto canvas = getCanvas();

    for(auto i = subwindows.begin(); i != subwindows.end(); ++i)
        drawChildWindow(canvas, *i);

    for (int h = 0; h  < height; ++h)
    {
        for (int w = 0; w < width; ++w)
            putchar(canvas[(h * width) + w]);
        putchar('\n');
    }
}

void MainWindow::drawChildWindow(ResizableWindow::canvas_type &canvas, ResizableWindow *child)
{
//    char* childCanvas = child->getCanvas();
//    int const m_h = getHeight(), m_w = getWidth();
//    int const c_h = child->getHeight(), c_w = child->getWidth();
//    int const c_x = child->getX(), c_y = child->getY();
//    int j_end = c_y + c_h < m_h ? c_y + c_h : m_h;
//    int i_end = c_x + c_w < m_w ? c_x + c_w : m_w;
//    i_end += m_w * c_y;
//    int x_tmp = 0, y_tmp = 0;
//    for (int j = c_y; j < j_end; j++) // height
//    {
//        x_tmp = c_w * y_tmp;
//        for(int i = m_w * j + c_x; i < i_end; i++)
//        {
//            *(mainWindow + i) = *(childCanvas + x_tmp);
//            ++x_tmp;
//        }
//        i_end += m_w;
//        y_tmp++;
//    }
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
