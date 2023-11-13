#include <iostream>
#include "graphics.h"

using namespace std;

class Point
{
    int x;
    int y;

    public:
        Point(int x=0, int y=0)
        {
            this->x = x;
            this->y = y;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        void setXY(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
}; // end class

class Line
{
    // Composition
    Point p1;
    Point p2;
    // Aggregation
    Point *ptr1;
    Point *ptr2;

    public:
        // Composition constructor
        Line(int x1, int y1, int x2, int y2) : p1(x1,y1), p2(x2,y2){}

        // Aggregation constructor
        Line(Point *ptr1, Point *ptr2)
        {
            this->ptr1 = ptr1;
            this->ptr2 = ptr2;
        }

        // Association constructor
        Line() {}

        void drawComposition()
        {
            line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        }

        void drawAggregation()
        {
            line((*ptr1).getX(), (*ptr1).getY(), (*ptr2).getX(), (*ptr2).getY());
        }

        void drawAssociation(Point p1, Point p2)
        {
            line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        }
}; // end class

class Circle
{
    int radius;
    // Composition
    Point center;
    // Aggregation
    Point *centerPtr;

    public:
        // Composition constructor
        Circle(int x, int y, int radius=50) : center(x,y) {}

        // Aggregation constructor
        Circle(Point *ptr, int radius=50) : centerPtr(ptr) {}

        // Association constructor
        Circle(int radius=50) {}

        void drawComposition()
        {
            circle(center.getX(), center.getY(), radius);
        }

        void drawAggregation()
        {
            circle((*centerPtr).getX(), (*centerPtr).getY(), radius);

        }

        void drawAssociation(Point center)
        {
            circle(center.getX(), center.getY(), radius);
        }
}; // end class

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Composition Line
    Line line1(20,40,80,90);
    line1.drawComposition();
    // Aggregation Line
    Point p1(120,280);
    Point p2(140,390);
    Line line2(&p1,&p2);
    line2.drawAggregation();
    // Association Line
    Line line3 = Line();
    line3.drawAssociation(Point(300,400), Point(250,350));

    // Composition Circle
    Circle circle1(30,15);
    circle1.drawComposition();
    // Aggregation Circle
    Point p3(61,67);
    Circle circle2(&p3, 80);
    circle2.drawAggregation();
    // Association Circle
    Circle circle3 = Circle();
    circle3.drawAssociation(Point(70,90));

    getch();
    closegraph();
}
