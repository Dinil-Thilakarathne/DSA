#include <iostream>
using namespace std;

int main() {
    double num = 9.75;
    int intNum = static_cast<int>(num); 

    cout << "Original: " << num << endl;
    cout << "Converted: " << intNum << endl;

    return 0;
}
