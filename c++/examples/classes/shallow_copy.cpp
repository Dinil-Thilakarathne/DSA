#include <iostream>
using namespace std;

class Box{
    public:
        int length;
        int *ptrLen;
        Box(){
            cout << "Default constructor called!" << endl;
        };
        Box(int l) {
            length = l;
            ptrLen = &length;
            cout <<  "Parameterized Constructor called" << endl;
        }

        // copy constructor for shallow copy
        Box(const Box& b){
            length = b.length;
            ptrLen = &length;
            cout << "Copy Constructor (shallow copy) called!" << endl;
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

    int *ptr1 = b1.ptrLen;
    int *ptr2 = b2.ptrLen;
    int *ptr3 = b3.ptrLen;

    cout << "Box 1 -> : " << ptr1 << endl;
    cout << "Box 2 -> : " << ptr2 << endl;
    cout << "Box 3 -> : " << ptr3 << endl;

}
