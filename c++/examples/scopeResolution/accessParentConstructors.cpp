#include <iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Base constructor called" << endl;
        }
        Base(int x){
            cout << "Base constructor called with value: " << x << endl;
        }
};

class Derived : public Base {
    using Base::Base;
    public:
        Derived(){ // Explicitly call Base constructor
            cout << "Derived constructor called" << endl;
        }
        Derived(int x){
            cout << "Derived constructor called with value: " << x << endl;
        }
};

int main() {
    Derived d, c(10);
    return 0;
}
