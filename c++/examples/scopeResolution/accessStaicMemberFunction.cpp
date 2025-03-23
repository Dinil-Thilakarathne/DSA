#include <iostream>
using namespace std;

class Counter{
    public:
        static int count; // static member

        Counter(){
            count++;
        }
};

int Counter::count = 0;

int main()
{
    Counter c1, c2, c3;
    cout << c1.count << endl;
    cout << "Count: " << Counter::count << endl;
}
