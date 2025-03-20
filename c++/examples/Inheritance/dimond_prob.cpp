#include <iostream>
using namespace std;

class Base {
    public:
        int value;
        Base() : value(0) {}
        void setValue(int v) { value = v; }
};

class Derived1 : public Base {};

class Derived2 : public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;

    // Accessing Base's member variables leads to ambiguity
    obj.Derived1::setValue(10); // Explicitly calling Derived1's Base
    obj.Derived2::setValue(20); // Explicitly calling Derived2's Base

    // obj.setValue(40); // make an ambiguous 

    cout << "Value from Derived1's Base: " << obj.Derived1::value << endl;
    cout << "Value from Derived2's Base: " << obj.Derived2::value << endl;

    // Ambiguity occurs if you directly try to access `value` or `setValue`.
    // obj.value; // Error: Ambiguous
    return 0;
}
