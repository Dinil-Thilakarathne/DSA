#include <iostream>
using namespace std;

namespace Space1 {
    int value = 10;
}

namespace Space2 {
    int value = 20;
}

int main() {
    cout << "Space1 value: " << Space1::value << endl;
    cout << "Space2 value: " << Space2::value << endl;
    return 0;
}
