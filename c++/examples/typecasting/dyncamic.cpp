#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {}  // Virtual function to enable polymorphism
};

class Derived : public Base {
public:
    void display() {
         cout << "Derived class function" <<  endl;
    }
};

int main() {
    Base* basePtr = new Derived();  // Upcasting (Base pointer to Derived object)

    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->display();  // Safe downcasting
    } else {
         cout << "Cast failed!" <<  endl;
    }

    delete basePtr;
    return 0;
}
