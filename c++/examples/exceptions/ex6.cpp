#include <iostream>
using namespace std;

void divide(int a, int b)
{
    if(b == 0){
        throw "Division by zero!";
    }
    cout << "Result: " << a/b << endl;
}

int main()
{
    try{
        divide(20, 4);
        divide(10, 0);
        divide(15, 5); // This line will not be executed because of the exception
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    return 0;
}
