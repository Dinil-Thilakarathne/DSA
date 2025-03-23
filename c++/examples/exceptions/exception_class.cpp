#include <iostream>
#include <exception>

int main() {
    try {
        throw std::runtime_error("Something went wrong!");
    }
    catch (std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
