#include "ResizableWindow.h"
#include <string>

class Window : public ResizableWindow
{
private:
	int x;
	int y;
    std::string name;
protected:

public:
    Window(int width, int height, std::string name);
    Window(int width, int height);
    Window(const Window& window);
	~Window();

    void setName(std::string name);
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    void move(int dx, int dy);
    std::string getName();
    int getX();
    int getY();
    char* getCanvas();

    Window& operator= (Window& window);
};

