#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "A" << endl;
        }
};

int main()
{
    try{
        A a;
        try {
            A b;
            throw 'x';
        }
        catch (...) {
            cout << "Inner Default Catch!" << endl;
        }
        throw '4';
        throw 10;
    }
    catch (int x) {
        cout << x << endl;
    }
    catch(...) {
        cout << "Default catch!" << endl;
    }
}
