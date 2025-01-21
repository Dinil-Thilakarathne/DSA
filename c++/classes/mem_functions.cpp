#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Declare friend function
    friend int getLength(const Box& b);
};

// Friend function definition
int getLength(const Box& b) {
    return b.length; // Accessing private member
}

int main() {
    Box box(10);
    cout << "Length of the box: " << getLength(box) << endl;
    return 0;
}
