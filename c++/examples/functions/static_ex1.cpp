#include <iostream>
using namespace std;

class MyClass {
public:
    static void show() {  // Static function definition
        cout << "Static function called!" << endl;
    }
};

int main() {
    MyClass::show();  // Calling static function without object
    return 0;
}
