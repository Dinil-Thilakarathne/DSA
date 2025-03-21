#include <iostream>
using namespace std;

// Engine class (a part of Car)
class Engine {
public:
    void start() { cout << "Engine started!" << endl; }
};

// Car class contains an Engine (Composition)
class Car {
private:
    Engine engine;  // Car "has-a" Engine

public:
    void startCar() {
        engine.start();  // Using Engine's method
        cout << "Car is ready to go!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.startCar();
    return 0;
}
