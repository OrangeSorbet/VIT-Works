#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age to see if you're eligible to vote: ";
    cin >> age;
    if (age >= 18) {
        cout << "You are eligible to vote!" << endl;
    } else {
        cout << "You are not eligible to vote." << endl;
    }
}