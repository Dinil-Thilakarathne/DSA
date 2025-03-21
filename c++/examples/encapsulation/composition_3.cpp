#include<iostream>
using namespace std;

class Engine {
private:
    int cylinders; // Number of cylinders
    double liters; // Capacity in liters

public:
    Engine(int c = 4, double l = 1.5);

    ~Engine();

    void displayEngine();
}e;

Engine::Engine(int cylinders, double liters)  {
    cout << "Constructor Engine init the variables" << endl;
    cout << "Cylinders: " << cylinders << endl;
    cout << "Liters: " << liters << endl;
}
void Engine::displayEngine(){
    cout << "Cylinders: " << cylinders << endl;
    cout << "Liters: " << liters << endl;
}
Engine::~Engine() {
    cout << "Destructor Called - Engine: " << cylinders << endl;
}


class Car {
private:
    int modelNumber; // Model number
    Engine motor; // Car's engine

public:
    Car(int m, int c, double l);
    Car(int m, Engine e);
};

Car::Car(int modelNumber, int c, double l)  : modelNumber(modelNumber), motor(c, l) {
    cout << "Constructor Car init the variables" << endl;
    cout << "Model No: " << modelNumber << endl;
}

Car::Car(int modelNumber, Engine e) : modelNumber(modelNumber), motor(e) {
    cout << "Constructor Car init the variables" << endl;
    cout << "Model No: " << modelNumber << endl;
}
int main() {
    Car c(2, 6, 2.8);
    Engine myEngine(8 , 2.4);
    Car myCar(3 , myEngine);
    return 0;
}
