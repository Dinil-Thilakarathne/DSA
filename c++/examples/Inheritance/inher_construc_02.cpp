#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class default constructor called with default value: 10 " << endl;
    }
    Base(int x) {
        cout << "Base class constructor called with value: " << x << endl;
    }
};

class Derived : public Base {
    using Base::Base; // Inheriting Base class constructors
    public:
        Derived() {
            cout << "Derived class default constructor called" << endl;
        }
        Derived(int x)  {
            cout << "Derived class constructor called" << endl;
        }
};

int main() {
    Derived d1, d2(20); // Calls Base(int)
    return 0;
}
