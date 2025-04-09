#include <iostream>
using namespace std;

class Vehicle {
    protected:
        string brand;
        string model;

    public:
        Vehicle(string b, string m) : brand(b), model(m) {}

        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
        virtual void fuelUp() = 0;

        virtual ~Vehicle() {}
};

class Car : public Vehicle {
    public:
        Car(string b, string m) : Vehicle(b, m) {}

        void startEngine() override {
            cout << "Car engine started" << endl;
        }

        void stopEngine() override {
            cout << "Car engine stopped" << endl;
        }

        void fuelUp() override {
            cout << "Filling petrol" << endl;
        }

        ~Car() override{
            cout << "Car destructor called!" << endl;
        }
};

class ElectricCar : public Vehicle {
    public:
        ElectricCar(string b, string m) : Vehicle(b, m) {}

        void startEngine() override {
            cout << "Electric motor started" << endl;
        }

        void stopEngine() override {
            cout << "Electric motor stopped" << endl;
        }

        void fuelUp() override {
            cout << "Charging battery" << endl;
        }

        ~ElectricCar() override{
            cout << "Electric Car destructor called!" << endl;
        }
};

int main()
{
    Car c("Toyota", "Corolla");
    ElectricCar ec("Tesla", "Model S");

    c.startEngine();
    c.stopEngine();
    c.fuelUp();

    ec.startEngine();
    ec.stopEngine();
    ec.fuelUp();

    return 0;
}
