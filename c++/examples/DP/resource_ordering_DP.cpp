#include <iostream>
#include <thread>
#include <mutex>

std::mutex r1, r2; // Two resources (mutex locks)

// Thread 1 Function
void process1() {
    std::cout << "Thread 1: Trying to acquire Resource 1\n";
    r1.lock(); // Acquire Resource 1
    std::cout << "Thread 1: Acquired Resource 1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Thread 1: Trying to acquire Resource 2\n";
    r2.lock(); // Acquire Resource 2
    std::cout << "Thread 1: Acquired Resource 2\n";

    // Critical Section (using both resources)
    std::cout << "Thread 1: Using both resources\n";

    r2.unlock();
    r1.unlock();
}

// Thread 2 Function
void process2() {
    std::cout << "Thread 2: Trying to acquire Resource 1\n";
    r1.lock(); // Request resources in the same order
    std::cout << "Thread 2: Acquired Resource 1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Thread 2: Trying to acquire Resource 2\n";
    r2.lock(); // Acquire Resource 2
    std::cout << "Thread 2: Acquired Resource 2\n";

    // Critical Section (using both resources)
    std::cout << "Thread 2: Using both resources\n";

    r2.unlock();
    r1.unlock();
}

int main() {
    std::thread t1(process1);
    std::thread t2(process2);

    t1.join();
    t2.join();

    return 0;
}
