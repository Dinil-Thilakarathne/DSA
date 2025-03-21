#include <iostream>
using namespace std;

class Cal{
    public:
        void add(int a, int b) {
            cout << a + b << endl;
        };

        void add(double a, double b){
            cout << a + b << endl;
        };

        void add(int a, int b, int c){
            cout << a + b + c << endl;
        };

};

int main(int argc, char const *argv[])
{
    /* code */
    Cal obj;

    obj.add(10.0f,20.0);

    return 0;
}

