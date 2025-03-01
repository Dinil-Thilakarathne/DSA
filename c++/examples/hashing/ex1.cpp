#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <algorithm>

class HashTable {
private:
    int tableSize;
    std::unordered_map<int, std::list<int>> table;

private:
    // Helper function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    // Helper function to find the next prime number greater than or equal to n
    int nextPrime(int n) {
        while (!isPrime(n)) {
            n++;
        }
        return n;
    }

public:
    // Constructor with table size (preferably a prime number)
    HashTable(int size) : tableSize(nextPrime(size)) {
        // No need to resize unordered_map
    }

    // Division method hash function
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return; // Key already exists, do not insert
            }
        }
        table[index].push_back(key);
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    // Delete a key from the hash table
    bool remove(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
            return true;
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            std::cout << "Bucket " << i << ": ";
            if (table.find(i) != table.end()) {
                for (int key : table[i]) {
                    std::cout << key << " -> ";
                }
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    std::vector<int> keys = {12, 23, 34, 45, 56, 67, 78, 89, 90};

    // Insert some values
    for (int key : keys) {
        hashTable.insert(key);
    }

    // Display the hash table
    std::cout << "Hash Table Contents:" << std::endl;
    hashTable.display();

    // Search for keys
    std::cout << "\nSearching for key 34: " << (hashTable.search(34) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for key 100: " << (hashTable.search(100) ? "Found" : "Not Found") << std::endl;

    // Remove a key
    std::cout << "\nRemoving key 34: " << (hashTable.remove(34) ? "Removed" : "Not Found") << std::endl;

    // Display the hash table after removal
    std::cout << "\nHash Table Contents after removal:" << std::endl;
    hashTable.display();

    return 0;
}
