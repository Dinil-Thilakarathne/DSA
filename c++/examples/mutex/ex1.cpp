#include <iostream>
#include <pthread.h>

pthread_mutex_t lock;  // Declare a mutex

void* threadFunction(void* arg) {
    pthread_mutex_lock(&lock);  // Lock mutex
    std::cout << "Thread " << pthread_self() << " is running\n";
    pthread_mutex_unlock(&lock);  // Unlock mutex
    return nullptr;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, nullptr);  // Initialize mutex

    pthread_create(&t1, nullptr, threadFunction, nullptr);
    pthread_create(&t2, nullptr, threadFunction, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    pthread_mutex_destroy(&lock);  // Destroy mutex
    return 0;
}
