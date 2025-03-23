#include <iostream>
using namespace std;

class MyClass {
    int a = 0;

    public:
    static int b;
    static void show() {  // Static function definition
        cout << "Static function called!" << endl;
        // a++; // cannot do this
        b++;
        cout << b << endl;
    }
};

int MyClass::b = 0;

int main() {
    MyClass::show();  // Calling static function without object
    return 0;
}
