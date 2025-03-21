#include <iostream>
using namespace std;

class A{
    public:
        int a;
    public:
        A(int x){
            a = x;
        }
};

class B{
    int b;

    public:
        B(int x){
            b = x;
        }

        void showAplusB(A& y, B& z){
            cout << "Show A + B=" << y.a + z.b << endl;
        }
};

int main()
{
    A a(5);
    B b(3);
    b.showAplusB(a,b);

    return 0;
}
