#include <iostream>
using namespace std;

class Box{
    public:
        int *length;
        Box(){
            cout << "Default constructor called!" << endl;
        };
        Box(int l) {
            length = new int(l);
            cout <<  "Parameterized Constructor called" << endl;
        }

        // copy constructor for deep copy
        Box(const Box& b){
            length = new int(*b.length);
            cout << "Copy Constructor (deep copy) called!" << endl;
        }

        void display(){
            cout << length;
        }
};


int main()
{
    Box b1(50);
    Box b2(b1);
    Box b3(b2);

    int *ptr1 = b1.length;
    int *ptr2 = b2.length;
    int *ptr3 = b3.length;

    cout << "Box 1 -> : " << ptr1 << endl;
    cout << "Box 2 -> : " << ptr2 << endl;
    cout << "Box 3 -> : " << ptr3 << endl;

}
