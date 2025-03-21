#include <iostream>
using namespace std;

int main() {
    try {
        int* largeArray = new int[100000];  // May cause bad_alloc error
        delete[] largeArray;
    } catch (bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    return 0;
}
