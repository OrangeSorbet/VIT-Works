#include <iostream>
using namespace std;

class Complex {
    float r, i;
public:
    Complex(float a = 0, float b = 0) { r = a; i = b; }
    friend Complex operator+(Complex a, Complex b) {
        return Complex(a.r + b.r, a.i + b.i);
    }
    void show() { cout << r << " + " << i << "i" << endl; }
};

int main() {
    Complex a(2, 3), b(1, 4);
    Complex c = a + b;
    c.show();
    return 0;
}
