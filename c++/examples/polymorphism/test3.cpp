#include <iostream>
using namespace std;
class Base{
   public:
     void func() {
        cout << "I ssssss" << endl;
     }

     Base() {
        cout << "I am in base" << endl;
}
};
class derived : public Base {
   public:
      void func()  {
      cout << "I am in derived class" << endl;
}
};
int main()
{
Base b;
derived d;
d.func();
return 0;
}
