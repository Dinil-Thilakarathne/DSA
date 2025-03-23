#include <iostream>
using namespace std;

class Base1 {
    public:
        void show() {
            cout << "Base1::show()" << endl;
        }
};

class Base2 {
    public:
        void show() {
            cout << "Base2::show()" << endl;
        }
};

class Derived : public Base1, public Base2 {
};

int main() {
    Derived d;
    // d.show(); // "Derived::show" is ambiguous
    d.Base1::show(); // Specify which base class to use
    d.Base2::show();
    return 0;
}
