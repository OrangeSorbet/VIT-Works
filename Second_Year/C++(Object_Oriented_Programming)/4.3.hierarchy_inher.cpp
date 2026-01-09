#include <iostream>

using namespace std;

// -----------------------------
// Base class: Shape
// -----------------------------
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double area() = 0;

    // Virtual destructor (important for polymorphism)
    virtual ~Shape() {}
};

// -----------------------------
// Derived class: Circle
// -----------------------------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;  // πr²
    }
};

// -----------------------------
// Derived class: Rectangle
// -----------------------------
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;  // l × w
    }
};

// -----------------------------
// Derived class: Triangle
// -----------------------------
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() override {
        return 0.5 * base * height;  // ½ × b × h
    }
};

// -----------------------------
// Main function
// -----------------------------
int main() {
    // Create pointers to Shape
    Shape* s1 = new Circle(5);       // Circle with radius 5
    Shape* s2 = new Rectangle(4, 6); // Rectangle 4x6
    Shape* s3 = new Triangle(3, 7);  // Triangle base=3, height=7

    // Display areas
    cout << "Circle area: " << s1->area() << endl;
    cout << "Rectangle area: " << s2->area() << endl;
    cout << "Triangle area: " << s3->area() << endl;

    // Free memory
    delete s1;
    delete s2;
    delete s3;

    return 0;
}