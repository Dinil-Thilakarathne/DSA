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

class Driver : private Vehicle {
public:
    void drive() {
        start();               // Accessible (public becomes private)
        protectedFunction();   // Accessible (protected becomes private)
        // privateFunction();  // Not accessible
    }
};

int main() {
    Driver myDriver;
    // myDriver.start(); // Not accessible (start is now private)
    myDriver.drive();    // Works because it is called internally
    return 0;
}

