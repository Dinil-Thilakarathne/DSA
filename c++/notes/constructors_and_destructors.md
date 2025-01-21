- [C++ constructors and destructors](#c-constructors-and-destructors)
  - [**1. Constructor**](#1-constructor)
    - [**Key Features of a Constructor:**](#key-features-of-a-constructor)
    - [**Types of Constructors**](#types-of-constructors)
    - [**Constructor Examples**](#constructor-examples)
  - [**2. Destructor**](#2-destructor)
    - [**Key Features of a Destructor:**](#key-features-of-a-destructor)
    - [**Destructor Example**](#destructor-example)
    - [**Use Cases of Destructors**](#use-cases-of-destructors)
  - [**3. Constructor and Destructor Sequence**](#3-constructor-and-destructor-sequence)
    - [**Example: Constructor and Destructor Order**](#example-constructor-and-destructor-order)
    - [**4. Constructor and Destructor in Dynamic Memory**](#4-constructor-and-destructor-in-dynamic-memory)

# C++ constructors and destructors

## **1. Constructor**

A **constructor** is a special member function in a class that is automatically called when an object of the class is created. Its purpose is to initialize the object's data members.

### **Key Features of a Constructor:**

- It has the same name as the class.
- It has no return type (not even `void`).
- It can be overloaded, meaning a class can have multiple constructors with different parameter lists.
- It can have default arguments.

---

### **Types of Constructors**

1. **Default Constructor**

    A constructor that takes no arguments or where all arguments have default values.

    ```cpp
    class Box {
    public:
        Box() {
            cout << "Default Constructor called" << endl;
        }
    };

    ```

2. **Parameterized Constructor**

    A constructor that takes arguments to initialize data members.

    ```cpp
    class Box {
    public:
        int length;

        Box(int l) { // Parameterized Constructor
            length = l;
            cout << "Parameterized Constructor called" << endl;
        }
    };

    ```

3. **Copy Constructor**

    A constructor that creates a new object as a copy of an existing object.

    ```cpp
    class Box {
    public:
        int length;

        Box(const Box& b) { // Copy Constructor
            length = b.length;
            cout << "Copy Constructor called" << endl;
        }
    };

    ```

4. **Defaulted and Deleted Constructors (C++11)**
    - **Defaulted Constructor**: Explicitly tells the compiler to generate a default constructor.

        ```cpp
        Box() = default;

        ```

    - **Deleted Constructor**: Prevents the compiler from generating a constructor.

        ```cpp
        Box() = delete;

        ```


---

### **Constructor Examples**

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    // Default Constructor
    Box() {
        length = 0;
        cout << "Default Constructor called" << endl;
    }

    // Parameterized Constructor
    Box(int l) {
        length = l;
        cout << "Parameterized Constructor called" << endl;
    }

    // Copy Constructor
    Box(const Box& b) {
        length = b.length;
        cout << "Copy Constructor called" << endl;
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1;            // Default Constructor
    Box b2(10);        // Parameterized Constructor
    Box b3(b2);        // Copy Constructor

    b1.display();
    b2.display();
    b3.display();

    return 0;
}

```

---

## **2. Destructor**

A **destructor** is a special member function in a class that is automatically called when an object goes out of scope or is explicitly deleted. Its purpose is to release resources that the object may have acquired during its lifetime (e.g., memory, file handles).

### **Key Features of a Destructor:**

- It has the same name as the class, preceded by a `~` (tilde).
- It takes no arguments.
- It has no return type.
- A class can only have one destructor.
- It is automatically invoked and cannot be overloaded or explicitly called.

---

### **Destructor Example**

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int* ptr;

    // Constructor
    Box() {
        ptr = new int; // Allocate memory
        cout << "Constructor: Memory allocated." << endl;
    }

    // Destructor
    ~Box() {
        delete ptr;    // Free memory
        cout << "Destructor: Memory deallocated." << endl;
    }
};

int main() {
    Box b1; // Constructor called
    // Destructor will be called automatically when b1 goes out of scope

    return 0;
}

```

---

### **Use Cases of Destructors**

- **Memory Management:** Release dynamically allocated memory.
- **File Management:** Close files.
- **Clean-up Tasks:** Free resources like network sockets, locks, etc.

---

## **3. Constructor and Destructor Sequence**

The order in which constructors and destructors are called is important:

- **Constructors**: Called in the order of object creation (from parent to child in inheritance).
- **Destructors**: Called in the reverse order of object destruction (from child to parent in inheritance).

---

### **Example: Constructor and Destructor Order**

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    Parent() {
        cout << "Parent Constructor" << endl;
    }

    ~Parent() {
        cout << "Parent Destructor" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "Child Constructor" << endl;
    }

    ~Child() {
        cout << "Child Destructor" << endl;
    }
};

int main() {
    Child c; // Parent Constructor -> Child Constructor
    // Child Destructor -> Parent Destructor (reverse order)

    return 0;
}

```

---

### **4. Constructor and Destructor in Dynamic Memory**

When objects are created dynamically using `new`, the destructor must be explicitly called if `delete` is used.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    Box() {
        cout << "Constructor called" << endl;
    }

    ~Box() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Box* b = new Box(); // Constructor called
    delete b;           // Destructor called

    return 0;
}

```

---

Let me know if you want to explore these concepts further with advanced examples or specific scenarios!
