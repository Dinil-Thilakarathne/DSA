#include <iostream>
using namespace std;

int value = 20;

int main()
{
    int value = 40;

    cout << value << endl;
    cout << ::value << endl; // output -> global scope variable
}
