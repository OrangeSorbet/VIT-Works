#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double x) { r = x; }
    double area() { return M_PI * r * r; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double a, double b) { l = a; w = b; }
    double area() { return l * w; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double x, double y) { b = x; h = y; }
    double area() { return 0.5 * b * h; }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);
    Shape* s3 = new Triangle(3, 7);
    cout << "Circle: " << s1->area() << endl;
    cout << "Rectangle: " << s2->area() << endl;
    cout << "Triangle: " << s3->area() << endl;
    delete s1; delete s2; delete s3;
    return 0;
}
