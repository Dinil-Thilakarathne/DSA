#include <iostream>
using namespace std;

void display() {
    cout << "Global display function" << endl;
}

class MyClass {
    public:
        void display() {
            cout << "Member display function" << endl;
        }

        void callGlobalDisplay() {
            ::display(); // Access global function
        }
};

int main() {
    MyClass obj;
    obj.display();
    obj.callGlobalDisplay();
    return 0;
}
