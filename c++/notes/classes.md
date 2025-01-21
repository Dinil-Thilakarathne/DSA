- [C++ Classes](#c-classes)
  - [**What is a Class?**](#what-is-a-class)
  - [**Basic Structure of a Class**](#basic-structure-of-a-class)
  - [**Key Concepts of Classes**](#key-concepts-of-classes)
  - [**1. Creating Classes and Objects**](#1-creating-classes-and-objects)
  - [**2. Using Constructors and Destructors**](#2-using-constructors-and-destructors)
    - [**Constructor:**](#constructor)
    - [**Destructor:**](#destructor)
  - [**3. Access Modifiers**](#3-access-modifiers)
  - [**4. Member Functions**](#4-member-functions)
  - [**5. Inheritance**](#5-inheritance)
  - [**6. Polymorphism**](#6-polymorphism)
  - [**7. Abstraction**](#7-abstraction)
  - [**8. Advanced Topics**](#8-advanced-topics)
    - [**Friend Functions:**](#friend-functions)
    - [**Operator Overloading:**](#operator-overloading)

# C++ Classes

## **What is a Class?**

A **class** is a blueprint for creating objects. It defines:

- **Data members** (attributes/properties): Variables that hold the state of the object.
- **Member functions** (methods): Functions that define the behavior of the object.

---

## **Basic Structure of a Class**

```cpp
#include <iostream>
using namespace std;

class Box { // Class definition
    private:
        int length; // Data member (private by default)

    public:
        // Member functions
        void setLength(int l) { // Setter method
            length = l;
        }

        int getLength() { // Getter method
            return length;
        }
};

int main() {
    Box box1; // Create an object of class Box
    box1.setLength(10); // Set length using member function
    cout << "Length: " << box1.getLength() << endl; // Access length using member function
    return 0;
}

```

---

## **Key Concepts of Classes**

1. **Access Modifiers**
    - **`private`**: Accessible only within the class.
    - **`protected`**: Accessible within the class and derived classes.
    - **`public`**: Accessible from outside the class.
2. **Objects**
    - Objects are instances of classes. For example, `Box box1;` creates an object of the `Box` class.
3. **Constructors**
    - Special functions that are automatically called when an object is created.
    - Used to initialize data members.

    ```cpp
    class Box {
        private:
            int length;

        public:
            Box(int l) { // Constructor
                length = l;
            }

            int getLength() {
                return length;
            }
    };

    int main() {
        Box box1(15); // Constructor initializes length
        cout << "Length: " << box1.getLength() << endl;
        return 0;
    }

    ```

4. **Destructor**
    - Special function that is automatically called when an object goes out of scope.
    - Used to clean up resources.

    ```cpp
    class Box {
        public:
            ~Box() { // Destructor
                cout << "Destructor called" << endl;
            }
    };

    ```

5. **Encapsulation**
    - Bundling data and methods together.
    - Controlled access to data using getters and setters.
6. **Inheritance**
    - One class (derived) inherits from another (base).
    - Example: A `Car` class can inherit properties from a `Vehicle` class.
7. **Polymorphism**
    - Using a common interface for different types.
    - Achieved through function overloading, operator overloading, and virtual functions.
8. **Abstraction**
    - Hiding implementation details and showing only essential features.
    - Achieved using classes and abstract classes.

---

## **1. Creating Classes and Objects**

A **class** is a blueprint, and an **object** is an instance of that class. You define a class and use it to create objects.

Example:

```cpp
class Car {
    public:
        string brand; // Public data member
        string model;
        int year;
};

int main() {
    Car car1; // Create an object of the class
    car1.brand = "Toyota"; // Access members using the dot operator
    car1.model = "Corolla";
    car1.year = 2020;

    cout << car1.brand << " " << car1.model << " " << car1.year << endl;
    return 0;
}

```

---

## **2. Using Constructors and Destructors**

### **Constructor:**

- A special function called automatically when an object is created.
- Used to initialize object members.

Example:

```cpp
class Car {
    public:
        string brand;
        int year;

        Car(string b, int y) { // Constructor
            brand = b;
            year = y;
        }
};

int main() {
    Car car1("Tesla", 2023); // Constructor initializes members
    cout << car1.brand << " " << car1.year << endl;
    return 0;
}

```

### **Destructor:**

- A special function called automatically when an object is destroyed.
- Used for cleanup (e.g., releasing memory).

Example:

```cpp
class Car {
    public:
        ~Car() { // Destructor
            cout << "Destructor called!" << endl;
        }
};

int main() {
    Car car1;
    return 0; // Destructor is automatically called here
}

```

---

## **3. Access Modifiers**

- **`private`**: Members are accessible only within the class.
- **`protected`**: Members are accessible in the class and its derived classes.
- **`public`**: Members are accessible from anywhere.

Example:

```cpp
class Box {
    private:
        int length; // Accessible only within the class

    public:
        void setLength(int l) { // Public function to set length
            length = l;
        }

        int getLength() { // Public function to get length
            return length;
        }
};

int main() {
    Box box;
    box.setLength(10); // Access through public function
    cout << box.getLength() << endl;
    return 0;
}

```

---

## **4. Member Functions**

- **Instance Member Functions:** Operate on the object’s data members.
- **Static Member Functions:** Operate on static data members shared by all objects.

Example of Static Members:

```cpp
class Box {
    public:
        static int count; // Static data member

        Box() {
            count++;
        }

        static int getCount() { // Static member function
            return count;
        }
};

int Box::count = 0; // Initialize static member

int main() {
    Box b1, b2, b3;
    cout << "Number of objects: " << Box::getCount() << endl;
    return 0;
}

```

---

## **5. Inheritance**

Inheritance allows a class to derive properties and behaviors from another class.

Example:

```cpp
class Vehicle {
    public:
        void start() {
            cout << "Vehicle started" << endl;
        }
};

class Car : public Vehicle { // Inherits from Vehicle
    public:
        void drive() {
            cout << "Car is driving" << endl;
        }
};

int main() {
    Car car1;
    car1.start(); // Inherited from Vehicle
    car1.drive(); // Defined in Car
    return 0;
}

```

---

## **6. Polymorphism**

- **Compile-Time Polymorphism:** Achieved via function overloading or operator overloading.
- **Run-Time Polymorphism:** Achieved via virtual functions.

Example of Function Overloading:

```cpp
class Print {
    public:
        void display(int x) {
            cout << "Integer: " << x << endl;
        }
        void display(double x) {
            cout << "Double: " << x << endl;
        }
};

int main() {
    Print obj;
    obj.display(10);
    obj.display(3.14);
    return 0;
}

```

Example of Virtual Functions (Run-Time Polymorphism):

```cpp
class Base {
    public:
        virtual void show() {
            cout << "Base class" << endl;
        }
};

class Derived : public Base {
    public:
        void show() override {
            cout << "Derived class" << endl;
        }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->show(); // Calls Derived class function
    return 0;
}

```

---

## **7. Abstraction**

Abstraction hides implementation details and provides a clear interface.

Example Using Abstract Classes:

```cpp
class Shape {
    public:
        virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
    public:
        void draw() override {
            cout << "Drawing Circle" << endl;
        }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}

```

---

## **8. Advanced Topics**

### **Friend Functions:**

Allow external functions or other classes to access private/protected members of a class.

```cpp
class Box {
    private:
        int length;

    public:
        Box(int l) : length(l) {}

        friend void printLength(Box b);
};

void printLength(Box b) {
    cout << "Length: " << b.length << endl; // Access private member
}

```

### **Operator Overloading:**

Define custom behavior for operators.

```cpp
class Complex {
    private:
        int real, imag;

    public:
        Complex(int r, int i) : real(r), imag(i) {}

        Complex operator+(Complex const &obj) {
            return Complex(real + obj.real, imag + obj.imag);
        }

        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}

```

---
