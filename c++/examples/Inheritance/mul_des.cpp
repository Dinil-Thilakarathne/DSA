#include <iostream>
using namespace std;

class A {
    public:
        A() {cout << "A" << endl; }
        ~A() {cout << "~A" << endl; }
};
class B{
    public:
        B() {cout << "B" << endl; }
        ~B() {cout << "~B" << endl; }
};
class C: public B, public A{
    public:
        C(){cout << "C" << endl;}
        ~C(){cout << "~C" << endl;}
};

int main()
{
    C c;
}
