#include <iostream>
using namespace std;

class Number {
    int n;
public:
    Number(int x) { n = x; }
    bool operator==(Number b) { return n == b.n; }
    bool operator<(Number b) { return n < b.n; }
};

int main() {
    Number a(5), b(7);
    cout << (a < b) << " " << (a == b) << endl;
    return 0;
}
