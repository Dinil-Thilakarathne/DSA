#include <iostream>
#include <math.h>
using namespace std;

class Shape {
    public:
    void calculateArea(int a){
        cout << "Area of circle: " << M_PI * a * a << endl;
    }

    void calculateArea(int a, int b){
        cout << "Area of rectangle: " << a * b << endl;
    }

    void calculateArea(double a, double b){
        cout << "Area of triangle: " << 0.5 * a * b << endl;
    }
};

int main() {
    int choice;
    Shape obj;

    cout << "Select a shape to calculate the area:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            int radius;
            cout << "Enter the radius of the circle:" ;
            cin >> radius;
            obj.calculateArea(radius);
            break;
        case 2:
            int length, breadth;
            cout << "Enter the length and breadth of the rectangle:" ;
            cin >> length >> breadth;
            obj.calculateArea(length, breadth);
            break;
        case 3:
            double base, height;
            cout << "Enter the base and height of the triangle:" ;
            cin >> base >> height;
            obj.calculateArea(base, height);
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
