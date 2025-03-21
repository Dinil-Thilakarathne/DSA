#include <iostream>
using namespace std;

// Engine class (a part of Car)
class Engine {
public:
    Engine() { cout << "Engine created!" << endl; }
    void start() { cout << "Engine started!" << endl; }
    ~Engine() { cout << "Engine destroyed!" << endl; }
};

// Car class (Composition with dynamic memory allocation)
class Car {
private:
    Engine* engine;  // Pointer to Engine (dynamically allocated)

public:
    Car() {
        engine = new Engine();  // Allocate memory for Engine
        cout << "Car created!" << endl;
    }

    void startCar() {
        engine->start();  // Using Engine's method
        cout << "Car is ready to go!" << endl;
    }

    ~Car() {
        delete engine;  // Free memory
        cout << "Car destroyed!" << endl;
    }
};

int main() {
    Car* myCar = new Car();  // Dynamic allocation of Car
    myCar->startCar();
    delete myCar;  // Proper cleanup
    return 0;
}
