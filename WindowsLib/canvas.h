#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

class CanvasWrapper;

class Canvas : public std::vector<char>
{
public:
    Canvas();
    Canvas(size_type n);
    Canvas(size_type width, size_type height);
    Canvas(const Canvas &second);
    ~Canvas();

    size_type getWidth() const;
    CanvasWrapper operator()(size_type i, size_type j);

private:
    size_type canvasWidth;
};

class CanvasWrapper
{
public:
    CanvasWrapper(Canvas *canvasPtr, Canvas::size_type i, Canvas::size_type j);
    ~CanvasWrapper();

    void operator=(Canvas::const_reference value);
    void operator=(Canvas::const_pointer value);

private:
    Canvas *canvas;
    Canvas::size_type row;
    Canvas::size_type column;

    void replaceValue(Canvas::const_pointer value);
};

#endif // CANVAS_H
