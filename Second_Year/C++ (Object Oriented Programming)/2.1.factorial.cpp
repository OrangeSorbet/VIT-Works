#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return 1;
    }

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    cout << "Factorial of " << number << " is: " << factorial(number) << endl;
}
