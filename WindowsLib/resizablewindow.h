#ifndef RESIZABLEWINDOW_H
#define RESIZABLEWINDOW_H

#include "window.h"
#include "canvas.h"

class ResizableWindow : public Window
{
public:
    ResizableWindow();
    ResizableWindow(int xpos, int ypos, const std::string &windowName,
                    int windowWidth, int windowHeight);
    ResizableWindow(const ResizableWindow &window);
    ~ResizableWindow();

    int getWidth() const;
    int getHeight() const;

    void setWidth(int windowWidth);
    void setHeight(int windowHeight);

    void changeSize(int dw, int dh);

    Canvas getCanvas() const;

protected:
    int width;
    int height;
};

#endif // RESIZABLEWINDOW_H
