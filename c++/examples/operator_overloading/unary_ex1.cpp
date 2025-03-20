#include <iostream>
using namespace std;

class Counter {
    private:
        int a, b;

    public:
        Counter(int a = 0, int b = 0) : a(a) , b(b) {}

        // Overload prefix ++ operator as a member function
        Counter& operator++() {
            ++a; ++b; // Increment the value
            return *this;
        }

        Counter& operator+() {
            a+=a;
            return *this;
        }

        Counter& operator--() {
            --a; --b;
            return *this;
        }

        Counter& operator-() {
            a-=a;
            return *this;
        }

        void display() const {
            cout << "A: " << a << " B: " << b << endl;
        }
};

int main() {
    Counter c1(5);

    -(+(+c1)); // Calls the overloaded ++ operator
    c1.display();

    return 0;
}
