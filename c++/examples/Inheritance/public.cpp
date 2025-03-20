#include <iostream>
using namespace std;

class Vehicle {
    public:
        void start() { cout << "Vehicle started" << endl; }
    protected:
        void protectedFunction() { cout << "Protected function in Vehicle" << endl; }
    private:
        void privateFunction() { cout << "Private function in Vehicle" << endl; }
};

class Car : public Vehicle {
    public:
        void showFeatures() {
            start();               // Accessible (public remains public)
            protectedFunction();   // Accessible (protected remains protected)
            // privateFunction();  // Not accessible (private remains private)
        }
};

int main() {
    Car myCar;
    myCar.start();  // Accessible
    // myCar.protectedFunction(); // Not accessible
    // myCar.showFeatures();
    return 0;
}
