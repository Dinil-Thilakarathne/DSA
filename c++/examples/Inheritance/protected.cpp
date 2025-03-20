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

class Car : protected Vehicle {
    public:
        void showFeatures() {
            start();               // Accessible (public becomes protected)
            protectedFunction();   // Accessible (protected remains protected)
            // privateFunction();  // Not accessible
        }
};

int main() {
    Car myCar;
    // myCar.start(); // Not accessible (start is now protected)
    myCar.showFeatures();  // Works because it is called internally
    return 0;
}
