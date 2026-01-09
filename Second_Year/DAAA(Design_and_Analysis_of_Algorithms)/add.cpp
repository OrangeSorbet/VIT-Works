#include <iostream>
#include <limits>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    while(!(cin >> a >> b)) {
        cout << "Please enter valid integer! - ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Sum: " << add(a, b) << endl;
}