#include <iostream>
#include <graphics.h>
using namespace std;

// Point class
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
}; // end Point class

class Line
{
    Point point1;
    Point point2;

public:
    Line() : point1(1, 2), point2(3, 4)
    {
        cout << "Line constructor <<default>>" << endl;
    }

    Line(int pointx1, int pointy1, int pointx2, int pointy2) : point1(pointx1, pointy1), point2(pointx2, pointy2) {}

    void setPoint1(int pointx1, int pointy1)
    {
        point1.setXandY(pointx1, pointy1);
    }

    void setPoint2(int pointx2, int pointy2)
    {
        point2.setXandY(pointx2, pointy2);
    }

    void printLine()
    {
        point1.print();
        point2.print();
    }
    void drawLine()
    {
        initwindow(400, 300, "Graphics Window");
        line(point1.getX(), point1.getY(), point2.getX(), point2.getY());
        //delay(5000);
        closegraph();
    }


    ~Line()
    {
        cout << "Destroy Line" << endl;
    }
};
class Line2
{
public:
    Line2()
    {
        cout << "Line2 constructor <<default>>" << endl;
    }
    void print (Point p1,Point p2)
    {
        p1.print();
        p2.print();
    }

    void drawLine(Point p1,Point p2)
    {
        initwindow(400, 300, "Graphics Window");
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        //delay(5000);
        closegraph();
    }
};//end class2
class Line3
{
    Point * startPoint;
    Point * endPoint;
public:
    Line3()
    {
        startPoint=NULL;
        endPoint=NULL;
    }
    Line3(Point* sPoint, Point* ePoint) : startPoint(sPoint), endPoint(ePoint)
    {
        cout << "Line3 constructor <<parameter>>" << endl;
    }
    void print()
    {
        if (startPoint != nullptr && endPoint != nullptr)
        {
            startPoint->print();
            endPoint->print();
        }
        else
        {
            cout << "Error: startPoint or endPoint is null." << endl;
        }
    }

    void drawLine()
    {
        if (startPoint != nullptr && endPoint != nullptr)
        {
            initwindow(400, 300, "Graphics Window");
            line(startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY());
            // delay(5000);
            closegraph();
        }
        else
        {
            cout << "Error: Cannot draw line, startPoint or endPoint is null." << endl;
        }
    }
};//end class3


int main()
{
    Line l1;
    l1.printLine();
    // l1.drawLine();

    Point pointA(2, 3);
    Point pointB(5, 6);

    Line2 l2;
    l2.print(pointA,pointB);
    // l2.drawLine(pointA, pointB);

    Point* s = new Point(1, 2);
    Point* e = new Point(3, 4);

    Line3 l3(s, e);
    l3.print();
    // l3.drawLine();
    return 0;
}
