#include <iostream>
using namespace std;

class A{
    private:
        int length;
    public:
        void setLength(int l);
        int getLength();
};

void A::setLength(int l){
    length = l;
}

int A::getLength(){
    return length;
}

int main(){
    A a;
    a.setLength(20);

    cout << a.getLength() << endl;
}
