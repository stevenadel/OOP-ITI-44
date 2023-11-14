#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
    protected:
        int x;
        int y;
        int color;

    public:
        Shape(int x, int y, int color);

        virtual void draw() = 0;
};
#endif // SHAPE_H
