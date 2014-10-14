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

CanvasWrapper Canvas::operator()(Canvas::size_type i, Canvas::size_type j)
{
    return CanvasWrapper(this, i, j);
}


CanvasWrapper::CanvasWrapper(Canvas *canvasPtr, Canvas::size_type i, Canvas::size_type j)
    : canvas(canvasPtr), row(i), column(j)
{
}

CanvasWrapper::~CanvasWrapper()
{
}

void CanvasWrapper::operator=(Canvas::const_reference value)
{
    replaceValue(&value);
}

void CanvasWrapper::operator=(Canvas::const_pointer value)
{
    replaceValue(value);
}

void CanvasWrapper::replaceValue(Canvas::const_pointer value)
{
    canvas[(canvas->getWidth() * row) + column] = *value;
}
