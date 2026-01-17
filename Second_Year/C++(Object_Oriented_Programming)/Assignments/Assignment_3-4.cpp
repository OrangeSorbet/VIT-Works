#include <iostream>
using namespace std;

class Sample {
    int x;
public:
    Sample(int x) { this->x = x; }
    void show() { cout << "Value of x: " << x << endl; }
};

int main() {
    Sample s(42);
    s.show();
    return 0;
}
