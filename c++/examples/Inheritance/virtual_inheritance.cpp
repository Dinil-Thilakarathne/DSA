#include <iostream>
using namespace std;

class Base {
public:
    int value;
    Base() : value(0) {
        cout << "Base class default constructor called" << endl;
    }

    Base(int v) : value(v) {
        cout << "Base class constructor called with value: " << v << endl;
    }
    void setValue(int v) { value = v; }
};

class Derived1 : virtual public Base {};

class Derived2 : virtual public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;

    // Now there's only one shared instance of Base
    obj.setValue(10); // No ambiguity, directly calls Base's method
    cout << "Shared Base value: " << obj.value << endl;

    // called grandparent parameterized constructor directly
    

    return 0;
}
