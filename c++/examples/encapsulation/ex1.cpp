#include <iostream>
using namespace std;

class Encapsulated {
    private:
        int privateVar;

    public:
        // Setter method to set the value of privateVar
        void setPrivateVar(int value) {
            privateVar = value;
        }

        // Getter method to get the value of privateVar
        int getPrivateVar() {
            return privateVar;
        }
};

int main() {
    Encapsulated obj;
    // obj.privateVar = 10; // Error: privateVar is private
    obj.setPrivateVar(42);
    cout << "The value of privateVar is: " << obj.getPrivateVar() << endl;
    return 0;
}
