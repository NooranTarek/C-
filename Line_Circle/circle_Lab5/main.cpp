#include <iostream>
#include <graphics.h>
using namespace std;

// Point class
class Point
{
    int x;
    int y;

public:
    Point() : x(100), y(60)
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


class Circle {
    Point center;
    int radius;

public:
    Circle() : center(100, 50), radius(40) {
        cout << "Circle1 constructor <<default>>" << endl;
    }

    Circle(int centerX, int centerY, int r) : center(centerX, centerY), radius(r) {
        cout << "Circle1 constructor <<parameter>>" << endl;
    }

    void setCenter(int centerX, int centerY) {
        center.setXandY(centerX, centerY);
    }

    void setRadius(int r) {
        radius = r;
    }

    void printCircle() {
        center.print();
        cout << "Radius: " << radius << endl;
    }

    void drawCircle() {
        initwindow(400, 300, "Graphics Window");
        circle(center.getX(), center.getY(), radius);
        getch();
        // delay(5000);
        closegraph();
    }

    ~Circle() {
        cout << "Destroy Circle1" << endl;
    }
};
class Circle2 {
public:
    Circle2(){
        cout << "Circle2 constructor <<default>>" << endl;
    }

    void printCircle(Point center,int radius) {
        center.print();
        cout << "Radius: " << radius << endl;
    }

    void drawCircle(Point center,int radius) {
        initwindow(400, 300, "Graphics Window");
        circle(center.getX(), center.getY(), radius);
        // delay(5000);
        getch();
        closegraph();

    }

    ~Circle2() {
        cout << "Destroy Circle2" << endl;
    }
};
class Circle3
{
    Point * center;
    int  radius;
public:
    Circle3()
    {
        center=NULL;
        radius=0;
    }

    void printCircle(Point* centerPoint, int  radiusValue)
    {
        center = centerPoint;
        radius = radiusValue;
        if (center != NULL && radius != 0)
        {
            center->print();
            cout<<radius<<endl;
        }
        else
        {
            cout << "Error: startPoint or endPoint is null." << endl;
        }
    }

    void drawCircle()
    {
        if (center != NULL && radius != 0)
        {
            initwindow(400, 300, "Graphics Window");
            circle(center->getX(), center->getY(), radius);
            getch();
            // delay(5000);
            closegraph();
        }
        else
        {
            cout << "Error: Cannot draw line, startPoint or endPoint is null." << endl;
        }
    }
        ~Circle3() {
        cout << "Destroy Circle3" << endl;
    }
};//end class3
int main()
{
    Circle C1;
    C1.printCircle();
    C1.drawCircle();

    /*Point pointA(50, 200);
    int radius=30;

    Circle2 C2;
    C2.printCircle(pointA,radius);
    C2.drawCircle(pointA, radius);

    Point point1(100, 22);
    int radius=20;
    Circle3 C3;
    C3.printCircle(&point1,radius);
    C3.drawCircle();*/
    return 0;
}
