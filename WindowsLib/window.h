#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window
{
public:
    Window();
    Window(int xpos, int ypos, std::string windowName);
    Window(const Window& window);
    ~Window();

    int getX() const;
    int getY() const;
    std::string getName() const;

    void setX(int xpos);
    void setY(int ypos);
    void setPosition(int xpos, int ypos);
    void setName(const std::string &newName);
    void move(int dx, int dy);

protected:
    int x;
    int y;
    std::string name;
};

#endif // WINDOW_H
