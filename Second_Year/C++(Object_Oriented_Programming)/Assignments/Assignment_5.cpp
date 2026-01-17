#include <iostream>
#include <stdexcept>
using namespace std;

class Calculator {
    double a, b;
public:
    Calculator(double x, double y) : a(x), b(y) {}
    double divide() {
        if (b == 0) throw runtime_error("Error: Division by zero!");
        return a / b;
    }
};

int main() {
    try {
        double x, y;
        cout << "Enter two numbers: ";
        if (!(cin >> x >> y)) throw invalid_argument("Invalid input!");
        Calculator c(x, y);
        cout << "Result = " << c.divide() << endl;
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
