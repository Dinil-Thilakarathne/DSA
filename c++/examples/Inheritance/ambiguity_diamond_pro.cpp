#include <iostream>
using namespace std;

class ClassA {
    public :
        int a;
};

class ClassB : public ClassA {
    public :
        int b;
};


class ClassC : public ClassA {
    public:
        int c;
};

class ClassD: public ClassB, public ClassC {
    public:
        int d;
};

int main()
{

    ClassD obj;

    obj.ClassB::a = 10;
    obj.ClassC::a = 20;
    obj.c = 30;
    obj.d = 40;
    cout << obj.ClassB::a << endl;
    cout << obj.ClassC::a << endl;
    cout << obj.c << endl;
    cout << obj.d ;

    puts("");
}

