#include <iostream>
using namespace std;

template <typename T, typename U, int n=0>
U abc(T x, U y) {return x + y + n ;}

int main()
{
    cout << abc<int, char>('A', 1); // T -> char , U -> int
    cout << abc<char, int, 10>('A', 1) << endl; // T -> int, U -> int
}
