#include <iostream>
using namespace std;

class A{
    public:
        virtual void func(int x=0, int y=0){
            cout << "Base class Func called: " << x + y << endl;
        };
};

class B: public A{
    public:
        void func(int x=0, int y=0) override{
            cout << "Derived class Func called: " << x  + y << endl;
        }
};


int main()
{
    A* basePtr;
    B b;
    basePtr = &b;
    basePtr->func(5,5);
}
