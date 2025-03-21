#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}


int main()
{
    cout << myMax(3,7) << endl;
    cout << myMax(3.4,7.5) << endl;
    cout << myMax('g','e') << endl;
}
