#include <iostream>
using namespace std;

class Counter {
    private:
        int value;

    public:
        Counter(int v = 0) : value(v) {}

        // Overload prefix ++ operator as a member function
        Counter& operator++() {
            ++value; // Increment the value
            return *this;
        }

        void display() const {
            cout << "Value: " << value << endl;
        }
};

int main() {
    Counter c1(5);

    ++c1; // Calls the overloaded ++ operator
    c1.display();

    return 0;
}
