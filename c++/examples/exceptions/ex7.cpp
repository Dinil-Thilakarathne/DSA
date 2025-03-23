#include <iostream>
using namespace std;

class A{
    public:
        A() {cout << "X";}
        ~A() {cout << "Y";}
};
class B{
    public:
        B() {cout << "K";}
        ~B() {cout << "L";}
};

int main()
{
    try {
        A a; B b;
        throw 10;
    }
    catch(...){
        cout << "Z " << endl;
    }
}
