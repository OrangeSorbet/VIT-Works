#include <iostream>
using namespace std;

class animal {
    public:
        void eat()
        {
            cout << "The animal ate food" << endl;
        }
};

class cat : public animal {
    public:
    void meow() {
        cout << "MEOWWWW" <<endl;
    }
};

int main() {
    cat mario;
    mario.meow();
    mario.eat();
    return 0;
}