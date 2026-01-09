#include <iostream>
using namespace std;

int main() {
    double length, width;

    cout << "Enter length: ";
    while (!(cin >> length) || length <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter a positive number for length: ";
    }

    cout << "Enter width: ";
    while (!(cin >> width) || width <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter a positive number for width: ";
    }

    double area = length * width;
    double perimeter = 2 * (length + width);

    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
}