#include <iostream>
using namespace std;

class Complex {
    private:
        double real, imag;

    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}

        // Overload + operator as a member function
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        void display() const {
            cout << real << " + " << imag << "i" << endl;
        }
};


int main() {
    Complex c1(2.5, 3.0), c2(1.5, 4.5);

    Complex c3 = c1 + c2; // Calls the overloaded + operator
    c3.display();

    return 0;
}
