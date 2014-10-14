#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

class Canvas : public std::vector<char>
{
public:
    Canvas();
    Canvas(size_type n);
    Canvas(size_type width, size_type height);
    Canvas(const Canvas &second);
    ~Canvas();

    size_type getWidth() const;

private:
    size_type canvasWidth;
};

#endif // CANVAS_H
