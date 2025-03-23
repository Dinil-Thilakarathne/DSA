#include <iostream>
using namespace std;

class A{
    public:
        virtual void func(int x=0, int y=0) = 0;
};

class B: public A{
    public:
        void func(int x=0, int y=0) override{
            cout << "Derived class Func called: " << x  + y << endl;
        }
};


int main()
{
    // A a;  cannot create objects from abstract classes
    A* basePtr;
    B b;
    basePtr = &b;
    basePtr->func(5,5);
}
