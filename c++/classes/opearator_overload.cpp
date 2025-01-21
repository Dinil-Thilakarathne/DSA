#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator as a member function
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

class Box {
private:
    int length, width, height;

public:
    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    // Overload == operator
    bool operator==(const Box& other) {
        return length == other.length && width == other.width && height == other.height;
    }
};

int main() {
    Complex c1(2.3, 4.5), c2(1.2, 3.4);

    Complex c3 = c1 + c2; // Calls the overloaded + operator
    c3.display();

    Box box1(10, 20, 30), box2(10, 20, 30), box3(15, 25, 35);

    if (box1 == box2)
        cout << "Box1 is equal to Box2" << endl;
    else
        cout << "Box1 is not equal to Box2" << endl;

    if (box1 == box3)
        cout << "Box1 is equal to Box3" << endl;
    else
        cout << "Box1 is not equal to Box3" << endl;

    return 0;
}
