#include <iostream>
using namespace std;

void Array(int size){
    try {
        int *arr = new int[size];
        cout << "Memory allocated for " << size << " integers!" << endl;
        if(!(arr)){
            throw "Memory allocation failed!";
        }
        delete[] arr;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}

int main()
{
    Array(10);
    Array(100000);
    Array(INT32_MAX);
}
