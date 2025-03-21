#include <iostream>
using namespace std;

template <typename T, typename U>
T add(T a, U b) {
    return a + b;
}


int main()
{
    cout << add(5, 3) << endl;  // Output: 8
    cout << add(3.5, 2) << endl;  // Output: 5.5
    cout << add(3, 'a') << endl;  // Output: 100 (3 + 'a' ASCII value)
    return 0;
}
