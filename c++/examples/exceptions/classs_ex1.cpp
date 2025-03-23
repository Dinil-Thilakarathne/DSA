#include <iostream>
using namespace std;

class Person{
    int age;

    public:
        void setAge(int a){
            if(a < 0){
                throw invalid_argument("Age cannot be negative");
            }
            age = a;
        }

        int getAge() {return age;}
};

int main()
{
    Person p;
    try
    {
        /* code */
        p.setAge(-5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}
