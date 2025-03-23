#include <iostream>
using namespace std;

template <int i>
void func(){
    // i = 20; // this cause run time error cannot modify i value (non-type constants)
    cout << i;
}

int main()
{
    func<20>();
}
