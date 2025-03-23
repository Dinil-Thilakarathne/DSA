#include <iostream>
using namespace std;

class Status {
    public:
        enum State { ACTIVE, INACTIVE };
};

int main() {
    cout << "Active: " << Status::ACTIVE << endl;
    cout << "Inactive: " << Status::INACTIVE << endl;
    return 0;
}
