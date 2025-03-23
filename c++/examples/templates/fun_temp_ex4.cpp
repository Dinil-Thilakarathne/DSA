#include <iostream>
using namespace std;

template <typename T, char c>
T add(T a) {
    return a + c;
}


int main()
{
    cout << add<int, 'A'>(2) << ", ";
    cout << add<char, 5>(2) << endl;
    return 0;
}
