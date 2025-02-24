#include <iostream>
#include <thread>
#include <mutex>

int counter = 0; // Shared resource
std::mutex mtx;  // Mutex object

void increment() {
    for (int i = 0; i < 1000000; i++) {
        mtx.lock();   // Lock before modifying shared data
        counter++;    // Critical Section
        mtx.unlock(); // Unlock after modification
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl; // Correct Output
    return 0;
}
