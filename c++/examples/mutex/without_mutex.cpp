#include <iostream>
#include <thread>

int counter = 0; // Shared resource

void increment() {
    for (int i = 0; i < 1000000; i++) {
        counter++;  // Race condition (multiple threads modifying shared data)
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl; // Incorrect output
    return 0;
}
