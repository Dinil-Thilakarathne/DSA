#include <iostream>
using namespace std;

int func(int num)
{
    if(num < 0) {
        return num;
    }
    else{
        throw 'A';
    }
}

int main(){
    int y = 10;

    try {
        cout << func(y);
    }
    catch(char ch){
        cout << ch;
    }
}
