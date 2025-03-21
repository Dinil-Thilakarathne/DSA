#include <iostream>
using namespace std;

class A{
    public:
        A() {
            cout << "A" << endl;
        }
};

class B{
    public:
        B() {
            cout << "B" << endl;
        }
        B(int x){
            cout << x << endl;
        }
};

class C: public B, public A{ // order matter
    public:
        C(int x) {
            cout << x << endl;
        }
};

int main()
{
    C(25);
}
