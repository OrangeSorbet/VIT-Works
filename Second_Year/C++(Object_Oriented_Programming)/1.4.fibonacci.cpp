#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int c;

    int num;
    cout << "Enter a number to print fibonacci series till that number: ";
    cin >> num;
    cout << "Fibonacci series:\n";
    for (int i = 1; i<=num; i++) {
        cout << a << "\n";
        c = a + b;
        a = b;
        b = c;
        if(a > num) {
            break;
        }
    }
}