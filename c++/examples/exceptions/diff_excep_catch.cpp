#include <iostream>

void testException(int value) {
    if (value == 1)
        throw 100;      // Throwing an integer
    else if (value == 2)
        throw "String Exception"; // Throwing a string
    else
        throw 3.14;     // Throwing a double
}

int main() {
    try {
        testException(3);
    }
    catch (int e) {
        std::cout << "Caught an integer: " << e << std::endl;
    }
    catch (const char* e) {
        std::cout << "Caught a string: " << e << std::endl;
    }
    catch (...) { // Default catch for any other type
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    return 0;
}
