#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main()
{
    cout << add(5, 3) << endl;  // Output: 8
    cout << add(3.5, 2.5) << endl;  // Output: 6
    return 0;
}
