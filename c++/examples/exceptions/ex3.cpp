#include <iostream>
using namespace std;

class Test {
    public:
        Test(){
            cout << "Constructor called!" << endl;
        }

        void anyError(){
            cout << "Sorry there is an Error!" << endl;
        }
};

int main()
{
    Test obj;

    try{
        throw obj; // Throw object of class Test (constructor called)
    }

    catch (Test e){
        e.anyError();
    }

    cout << "Error handled!" << endl;
}
