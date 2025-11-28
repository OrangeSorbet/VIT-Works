#include <iostream>
using namespace std;

class living {
    public:
    void breathe() {
        cout << "The living being is breathing" << endl;
    }
};

class animal : public living {
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
    mario.breathe();
    return 0;
}