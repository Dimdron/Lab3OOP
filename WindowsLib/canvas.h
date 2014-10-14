#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

class Canvas : public std::vector<char>
{
public:
    Canvas();
    Canvas(size_type n);
    Canvas(const Canvas &second);
    ~Canvas();
};

#endif // CANVAS_H
