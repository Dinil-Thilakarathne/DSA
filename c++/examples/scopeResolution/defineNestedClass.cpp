#include <iostream>
using namespace std;

class Outside{
    public:
        int x = 0;

        Outside() {
            cout << "Outside default Constructor!" << endl;
            Inside b;
        }

        class Inside{
            public :
                int x = 1;
                int y = 0;

                Inside(){
                    cout << "Inside default Constructor!" << endl;
                }

                int foo(){
                    return x;
                }
        };
};


int main()
{
    Outside A;
    Outside::Inside B;
    cout<<B.foo()<<endl;
    // cout<<B.y<<endl;
}
