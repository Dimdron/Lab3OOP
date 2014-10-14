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

    void operator=(Canvas::value_type value);
    Canvas::value_type operator*();

private:
    Canvas *canvas;
    Canvas::size_type row;
    Canvas::size_type column;
};

#endif // CANVAS_H
