#include <iostream>
#include <limits>
using namespace std;

int compare(int a, int b) {
    int c = a-b;
    if(c < 0) {
        cout << b << " is larger" << endl;
    }
    else if (c > 0) {
        cout << a << " is larger" << endl;
    }
    else cout << "Numbers are equal";
}

int main() {
    int a, b;
    cout << "Enter 2 integers to compare them - ";
    while(!(cin >> a >> b)) {
        cout << "Please enter a valid integer - ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    compare(a, b);
}