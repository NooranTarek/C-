#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0)
    {
        cout << "Point constructor <<default>>" << endl;
    }

    Point(int x1, int y1) : x(x1), y(y1)
    {
        cout << "Point constructor <<parameter>>" << endl;
    }

    void setX(int x1)
    {
        x = x1;
    }

    void setY(int y1)
    {
        y = y1;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void setXandY(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    ~Point()
    {
        cout << "Destroy Point" << endl;
    }
};

class Shape
{
protected:
    int color;
    Point point1;
    Point point2;

public:
    Shape(int _color = 0) : point1(100, 50), point2(200, 30)
    {
        color = _color;
    }
    Shape(int pointx1, int pointy1, int pointx2, int pointy2, int _color = 0) : point1(pointx1, pointy1), point2(pointx2, pointy2)
    {
        color = _color;
    }
    Shape(int pointx1, int pointy1, int _color = 0) : point1(pointx1, pointy1)
    {
        color = _color;
    }
    void setColor(int _color)
    {
        color = _color;
    }

    int getColor()
    {
        return color;
    }

    void setPoint1(int pointx1, int pointy1)
    {
        point1.setXandY(pointx1, pointy1);
    }

    void setPoint2(int pointx2, int pointy2)
    {
        point2.setXandY(pointx2, pointy2);
    }

    void printShapePoints()
    {
        point1.print();
        point2.print();
    }

    void printShapeAttributes()
    {
        cout << "Color: " << color << endl;
    }

    virtual void draw() = 0;
};

class Rectanglee : public Shape
{
public:
    Rectanglee() : Shape(0)
    {
    }
    Rectanglee(int pointx1, int pointy1, int pointx2, int pointy2, int _color) : Shape(pointx1, pointy1, pointx2, pointy2)
    {
        color = _color;
    }
    void draw()
    {
        //initwindow(800, 500, "Welcome");
        setColor(color);
        rectangle(point1.getX(), point1.getY(), point2.getX(), point2.getY());
        //floodfill((point1.getX() + point2.getX()) / 2, (point1.getY() + point2.getY()) / 2, color);
        //getch();
    }
};

class Circle : public Shape
{
    int radius;

public:
    Circle() : Shape(0), radius(40) {}
    Circle(int pointx1, int pointy1, int r, int _color) : Shape(pointx1, pointy1)
    {
        radius = r;
        color = _color;
    }
    void setRadius(int r)
    {
        radius = r;
    }

    int getRadius()
    {
        return radius;
    }

    void draw()
    {
        //initwindow(300, 400, "welcome");
        setColor(color);
        circle(point1.getX(), point1.getY(), radius);
        //floodfill(point1.getX(), point1.getY(), color);
        // getch();
    }
};

class Line : public Shape
{
public:
    Line() : Shape(0) {}
    Line(int pointx1, int pointy1, int pointx2, int pointy2, int _color) : Shape(pointx1, pointy1, pointx2, pointy2)
    {
        color = _color;
    }
    void draw()
    {
        // initwindow(800, 500, "Welcome");
        //initwindow(300, 400, "welcome");
        setColor(color);
        line(point1.getX(), point1.getY(), point2.getX(), point2.getY());
        // getch();
    }
};

int main()
{
    int numberOfShapes;
    cout << "please enter the number of shapes to draw";
    cin >> numberOfShapes;

    Shape *shapes[numberOfShapes];
    for (int i = 0; i < numberOfShapes; i++)
    {
        int shapeNumber;
        cout << "Hello Sir, please enter the number of the shape you want to appear from this list" << endl
             << "(1) line " << endl
             << "(2) rectangle " << endl
             << "(3) circle " << endl;
        cin >> shapeNumber;
        if (shapeNumber == 1)
        {
            int x1, y1, x2, y2, color;
            cout << "Enter coordinates (x1 y1 x2 y2 color) for the line: ";
            cin >> x1 >> y1 >> x2 >> y2 >> color;

            //Line l1(x1, y1, x2, y2, color);
            //l1.draw();
            shapes[i] = new Line(x1, y1, x2, y2, color);
        }
        else if (shapeNumber == 2)
        {
            int x1, y1, x2, y2, color;
            cout << "Enter coordinates (x1 y1 x2 y2 color) for the rectangle: ";
            cin >> x1 >> y1 >> x2 >> y2 >> color;

            //Rectanglee r1(x1, y1, x2, y2, color);
            //r1.draw();
            shapes[i] = new Rectanglee(x1, y1, x2, y2, color);
        }
        else if (shapeNumber == 3)
        {
            int x, y, radius, color;
            cout << "Enter coordinates (x y radius color) for the circle: ";
            cin >> x >> y >> radius >> color;
            //Circle c1(x, y, radius,color);
            //c1.draw();
            shapes[i] = new Circle(x, y, radius, color);
        }
    }
    initwindow(300, 400, "graph");
    for (int i = 0; i < numberOfShapes; i++)
    {
        shapes[i]->draw();
    }
    getch();
    closegraph();

    return 0;
}
