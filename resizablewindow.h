#pragma once
#include "window.h"
#include <vector>

class ResizableWindow : public Window
{
public:
    typedef std::vector<char> canvas_type;

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

    canvas_type getCanvas() const;

protected:
    int width;
    int height;
};

