#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(10, 20) << endl;
    cout << myMax(3.5, 2.8) << endl;
    cout << myMax('A', 'Z') << endl;
    return 0;
}
