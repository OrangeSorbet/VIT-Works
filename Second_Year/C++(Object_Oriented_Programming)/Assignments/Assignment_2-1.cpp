#include <iostream>
using namespace std;

int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial = " << factorial(n) << endl;
    return 0;
}
