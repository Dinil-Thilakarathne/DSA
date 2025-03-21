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
        int cylinders;
        double liters;

    public:
        Car(int cyl, double lit) : cylinders(cyl), liters(lit) {
            cout << "Car created!" << endl;
        }

        void startCar() {
            engine.start();  // Using Engine's method
            cout << "Car with " << cylinders << " cylinders and " << liters << " liters is ready to go!" << endl;
        }
};



int main() {
    Car myCar(4,5.0f);
    myCar.startCar();
    return 0;
}
