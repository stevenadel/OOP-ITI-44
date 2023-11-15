#include <iostream>
#include "graphics.h"
#include "shape.h"

using namespace std;

class Circle : public Shape
{
    int radius;

    public:
        Circle(int x, int y, int radius, int color) : Shape(x, y, color)
        {
            this->radius = radius;
        }

        void draw()
        {
            setcolor(color);
            circle(x, y, radius);
        }

        friend istream &operator >> (istream &input, Circle &c)
        {
            input >> c.x >> c.y >> c.radius >> c.color;
            return input;
        }
}; //end class Circle

class Rect : public Shape
{
    int x2;
    int y2;

    public:
        Rect(int x, int y, int x2, int y2, int color = WHITE) : Shape(x, y, color)
        {
            this->x2 = x2;
            this->y2 = y2;
        }

        void draw()
        {
            setcolor(color);
            rectangle(x,y,x2,y2);
        }

        friend istream &operator >> (istream &input, Rect &r)
        {
            input >> r.x >> r.y >> r.x2 >> r.y2 >> r.color;
            return input;
        }
}; //end class Rect

class Line : public Shape
{
    int x2;
    int y2;

    public:
        Line(int x, int y, int x2, int y2, int color = WHITE) : Shape(x, y, color)
        {
            this->x2 = x2;
            this->y2 = y2;
        }

        void draw()
        {
            setcolor(color);
            line(x,y,x2,y2);
        }

        friend istream &operator >> (istream &input, Line &l)
        {
            input >> l.x >> l.y >> l.x2 >> l.y2 >> l.color;
            return input;
        }
}; //end class Line

int main()
{
    int n;
    cout << "How many objects are you going to enter: ";
    cin >> n;

    Shape *arr[n];

    char shape;
    int x, y, x2, y2, radius, color;
    for (int i = 0; i < n; i++)
    {
        cout << "Choose shape [c for circle/r for rect/l for line]: ";
        cin >> shape;

        if ('r' == shape || 'l' == shape)
        {
            cout << "Enter point x: ";
            cin >> x;
            cout << "Enter point y: ";
            cin >> y;
            cout << "Enter point x2: ";
            cin >> x2;
            cout << "Enter point y2: ";
            cin >> y2;
        }
        else if ('c' == shape)
        {
            cout << "Enter point x: ";
            cin >> x;
            cout << "Enter point y: ";
            cin >> y;
            cout << "Enter radius: ";
            cin >> radius;
        }
        else
        {
            cout << "Please choose a valid shape." << endl;
            exit(1);
        }

        cout << "Choose color (integer from 0-15): ";
        cin >> color;
        if (color > 15 || color < 0) { color = WHITE; }

        if ('c' == shape)
        {
            arr[i] = new Circle(x, y, radius, color);
        }
        else if ('r' == shape)
        {
            arr[i] = new Rect(x, y, x2, y2, color);
        }
        else if ('l' == shape)
        {
            arr[i] = new Line(x, y, x2, y2, color);
        }
    }

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    for (int i = 0; i < n; i++)
    {
        arr[i]->draw();
    }

    getch();
    closegraph();
}
