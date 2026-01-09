#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    cout << "Enter two integers to find GCD: ";
    cin >> x >> y;
    cout << "The GCD of " << x << " and " << y << " is " << gcd(x, y);
    return 0;
}