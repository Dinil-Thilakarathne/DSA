#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "A" << endl;
        }
};

class B: public A{
    public:
        B() {
            cout << "B" << endl;
        }
};

int main()
{
    try{
        B b; throw b;
    }
    catch (A a) {
        cout << "A" << endl;
    }
    catch (B b) {
        cout << "B" << endl;
    }
    catch(...) {
        cout << "Default catch!" << endl;
    }
}
