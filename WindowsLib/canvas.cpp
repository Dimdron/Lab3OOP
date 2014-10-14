#include "canvas.h"

Canvas::Canvas()
{
}

Canvas::Canvas(Canvas::size_type n)
    : std::vector<char>(n)
{
}

Canvas::Canvas(Canvas::size_type width, Canvas::size_type height)
    : Canvas(width * height)
{
     canvasWidth = width;
}

Canvas::Canvas(const Canvas &second)
    : std::vector<char>(second)
{
}

Canvas::~Canvas()
{
}

Canvas::size_type Canvas::getWidth() const
{
    return canvasWidth;
}
