#include <iostream>
using namespace std;

class Counter {
    private :
        int a, b;

    public:
        Counter(int a=0, int b=0): a(a) , b(b) {}

        Counter operator+(const Counter& other ) const {
            return Counter(a + other.a, b + other.b); // call the function and create object
        }

        Counter operator-(const Counter& other) const {
            return Counter(a - other.a, b - other.b);
        }

        void operator==(const Counter& other) const {
            cout << ((a == other.a) ? "Object matched!" : "Objects doesn't match!");
            cout << endl;
        }

        void printOut() {
            cout << "a: " << a << " b: " << b << endl;
        }

};

int main()
{
    Counter obj1(5,10), obj2(5,10);

    Counter obj3 = obj1 + obj2;
    Counter obj4 = obj1 - obj2;

    obj1==obj2;

    obj3.printOut();
    obj4.printOut();

}
