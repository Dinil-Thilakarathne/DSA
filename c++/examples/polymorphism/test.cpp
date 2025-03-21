#include <iostream>
using namespace std;

class A {
    public:
        A() {cout << "A"; }
        A(int x) {cout << "xA"; }
};
class B{
    public:
        B() {cout << "B"; }
        B(int x) {cout << "xB"; }
};
class C: public B, public A{
    public:
        C(int x){
            cout << int('A') << endl;
        }
};

int main()
{
    C c(20);
}
