#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() {} // Virtual destructor
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animals[] = {new Dog(), new Cat(), new Animal()};

    // Virtual dispatch in action
    for(int i = 0; i < 3; i++) {
        animals[i]->makeSound(); // Calls correct version based on actual object type
    }

    // Clean up
    for(int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}
