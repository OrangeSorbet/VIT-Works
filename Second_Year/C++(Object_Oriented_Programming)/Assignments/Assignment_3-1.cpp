#include <iostream>
using namespace std;

class Rectangle {
    float length, width;
public:
    Rectangle(float l, float w) { length = l; width = w; }
    float area() { return length * width; }
    float perimeter() { return 2 * (length + width); }
};

int main() {
    float l, w;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;
    Rectangle r(l, w);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    return 0;
}
