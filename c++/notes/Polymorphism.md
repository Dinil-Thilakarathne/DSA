- [Polymorphism C++](#polymorphism-c)
    - [**Polymorphism in C++**](#polymorphism-in-c)
    - [**Types of Polymorphism in C++**](#types-of-polymorphism-in-c)
  - [**1. Compile-time (Static) Polymorphism**](#1-compile-time-static-polymorphism)
    - [**A. Function Overloading**](#a-function-overloading)
    - [**B. Operator Overloading**](#b-operator-overloading)
  - [**2. Run-time (Dynamic) Polymorphism**](#2-run-time-dynamic-polymorphism)
    - [**A. Function Overriding**](#a-function-overriding)
    - [**B. Abstract Classes and Pure Virtual Functions**](#b-abstract-classes-and-pure-virtual-functions)
  - [**Key Differences Between Static and Dynamic Polymorphism**](#key-differences-between-static-and-dynamic-polymorphism)
    - [**Conclusion**](#conclusion)

# Polymorphism C++

### **Polymorphism in C++**

Polymorphism is a key concept in Object-Oriented Programming (OOP) that allows one interface to be used for different data types. It enables objects of different classes to be treated as objects of a common base class, making code more flexible and reusable.

### **Types of Polymorphism in C++**

1. **Compile-time (Static) Polymorphism**
    - Achieved using **Function Overloading** and **Operator Overloading**.
    - Decided at compile time.
2. **Run-time (Dynamic) Polymorphism**
    - Achieved using **Virtual Functions** and **Function Overriding**.
    - Decided at runtime using **pointers or references** to base class objects.

---

## **1. Compile-time (Static) Polymorphism**

### **A. Function Overloading**

Function overloading allows multiple functions with the same name but different parameters.

Example:

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

int main() {
    Math obj;
    cout << obj.add(5, 10) << endl;      // Calls int version
    cout << obj.add(5.5, 10.2) << endl;  // Calls double version
    cout << obj.add(1, 2, 3) << endl;    // Calls 3-parameter version
    return 0;
}

```

**Output:**

```
15
15.7
6

```

---

### **B. Operator Overloading**

Allows operators like `+`, `-`, `*`, etc., to be overloaded for user-defined types.

Example:

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() { cout << real << " + " << imag << "i" << endl; }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}

```

**Output:**

```
4 + 9i

```

---

## **2. Run-time (Dynamic) Polymorphism**

### **A. Function Overriding**

Occurs when a derived class provides a new implementation of a function from the base class.

Example:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class show function" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class show function" << endl; }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;
    bptr->show(); // Calls Derived class function due to virtual function
    return 0;
}

```

**Output:**

```
Derived class show function

```

- Without `virtual`, the **base class function would have been called** instead.

---

### **B. Abstract Classes and Pure Virtual Functions**

An **abstract class** has at least one **pure virtual function**, making it a blueprint for derived classes.

Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function (abstract class)
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing Square" << endl; }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Square();
    s1->draw(); // Calls Circle's draw
    s2->draw(); // Calls Square's draw
    delete s1;
    delete s2;
    return 0;
}

```

**Output:**

```
Drawing Circle
Drawing Square

```

- **Pure virtual functions** force derived classes to provide their own implementation.

---

## **Key Differences Between Static and Dynamic Polymorphism**

| Feature | Static Polymorphism (Compile-time) | Dynamic Polymorphism (Run-time) |
| --- | --- | --- |
| Achieved By | Function/Operator Overloading | Function Overriding |
| Binding Time | Compile-time | Run-time |
| Performance | Faster (Resolved at compile time) | Slower (Resolved at run time via vtable) |
| Function Selection | Based on function signature | Based on the object type |

---

### **Conclusion**

- **Use function overloading** when methods serve similar purposes but take different parameters.
- **Use operator overloading** when making user-defined classes behave like built-in types.
- **Use function overriding** when a derived class needs to customize a function from the base class.
- **Use abstract classes** when defining common behavior that must be implemented by subclasses.
