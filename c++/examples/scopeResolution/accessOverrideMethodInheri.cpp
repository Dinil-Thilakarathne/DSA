#include <iostream>
using namespace std;

class Base {
    public:
        void display() {
            cout << "Base display" << endl;
        }
};

class Derived : public Base {
    public:
        void display() {
            cout << "Derived display" << endl;
        }

        void showBaseDisplay() {
            Base::display(); // Call the base class method
        }
};

int main() {
    Derived d;
    d.display();
    d.showBaseDisplay();
    return 0;
}
