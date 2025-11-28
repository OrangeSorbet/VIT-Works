#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
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
        cout << "Negative numbers can't be prime." << endl;
        return 1;
    }

    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;
}
