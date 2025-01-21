#include <iostream>
using namespace std;

class Simple {
    public:
        Simple(){ // Constructor
            cout << "Hello World!" << endl;
        }

        ~Simple(){ // Destructor
            cout << "Goodbye World!" << endl;
        }
};

class Date {
    private:
        int day, month, year;

    public:
        Date(int d, int m, int y){ // Constructor
            day = d;
            month = m;
            year = y;
        }

        void printDate(){
            cout << day << "/" << month << "/" << year << endl;
        }
};

int main(){
    Date date(10, 12, 2020);
    date.printDate();

    Simple simple;
    return 0;
}
