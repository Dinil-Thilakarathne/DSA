#include <iostream>
using namespace std;

class Sample {
    int *id;
    public:
    Sample() : id(nullptr) {}

    void init(int x) {
        if (id == NULL) {
            id = new int; // Allocate memory
        }
        *id = x;
    }
    void display() {
        cout << endl << "ID = " << *id;
    }
    // Deep copy constructor
    Sample(const Sample &obj) {
        id = new int; // Allocate memory
        *id = *(obj.id); // Copy the value

    };

    // Destructor to free allocated memory
    ~Sample() {
        delete id;
    }
};

int main() {
    int x = 100;

    Sample obj1;
    obj1.init(x);
    obj1.display();

    Sample obj2(obj1);
    obj2.display();

    int y = 200;
    obj2.init(y);
    obj1.display();
    obj2.display();

    cout << endl;
    return 0;
}
