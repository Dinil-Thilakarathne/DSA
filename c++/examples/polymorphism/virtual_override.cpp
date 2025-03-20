#include <iostream>
using namespace std;

class Base {
    public:
        virtual void show() { cout << "Base class show function" << endl; }
};

class Derived : public Base {
    public:
        void show() override { cout << "Derived class show function" << endl; }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;
    bptr->show(); // Calls Derived class function due to virtual function
    return 0;
}
