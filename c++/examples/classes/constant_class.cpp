#include <iostream>
using namespace std;

class Test {
    private:
        int value;
        mutable int advanceValue; // mutable overrides const restrictions for the variable.
    public:
        Test(int v) : value(v) {}

        void setValue(int v) { value = v; } // Non-const function

        void show() const {  // Const function (can be called by const objects)
            // value = 10; // expression must be a modifiable lvalue
            cout << "Value: " << value << endl;
        }

        void advanceShow() const{
            advanceValue = 20;
            cout << "Mutable variable value: " << advanceValue << endl;
        }
};

int main() {
    const Test obj(10);  // Creating a constant object
    obj.show();          // ✅ Allowed (const function)

    // obj.setValue(20);  // ❌ ERROR: Cannot call non-const function on const object

    const Test advanceObj(20);
    obj.advanceShow();
    return 0;
}
