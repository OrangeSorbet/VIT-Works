#include <iostream>
using namespace std;

int main() {
    cout << "Enter temperature in Celsius: ";
    double celsius;
    cin >> celsius;
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
}