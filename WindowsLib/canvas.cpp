#include "canvas.h"

Canvas::Canvas()
{
}

Canvas::Canvas(Canvas::size_type n)
    : std::vector<char>(n)
{
}

Canvas::Canvas(const Canvas &second)
    : std::vector<char>(second)
{
}

Canvas::~Canvas()
{
}
