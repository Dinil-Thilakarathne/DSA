- [C++ scope resolution operator](#c-scope-resolution-operator)
    - [**1. Accessing Global Variables**](#1-accessing-global-variables)
    - [**2. Defining Class Member Functions Outside the Class**](#2-defining-class-member-functions-outside-the-class)
    - [**3. Accessing Static Members of a Class**](#3-accessing-static-members-of-a-class)
    - [**4. Resolving Ambiguity in Multiple Inheritance**](#4-resolving-ambiguity-in-multiple-inheritance)
    - [**5. Accessing Namespace Members**](#5-accessing-namespace-members)
    - [**6. Accessing Class Constructors in Derived Classes**](#6-accessing-class-constructors-in-derived-classes)
    - [**7. Accessing Enclosed Enumerations**](#7-accessing-enclosed-enumerations)
    - [**8. Accessing Overridden Methods in Inheritance**](#8-accessing-overridden-methods-in-inheritance)
    - [**9. Accessing Global Functions Hidden by Local or Member Functions**](#9-accessing-global-functions-hidden-by-local-or-member-functions)

# C++ scope resolution operator

The **scope resolution operator** (`::`) in C++ is used to access or specify something outside the current scope, such as a global variable, a class member, or a namespace. Below are the common use cases of the scope resolution operator:

---

### **1. Accessing Global Variables**

When a local variable hides a global variable, the `::` operator is used to access the global variable.

#### Example:

```cpp
#include <iostream>
using namespace std;

int value = 10; // Global variable

int main() {
    int value = 20; // Local variable
    cout << "Local value: " << value << endl;
    cout << "Global value: " << ::value << endl; // Access global variable
    return 0;
}

```

---

### **2. Defining Class Member Functions Outside the Class**

You can use the scope resolution operator to define member functions of a class outside its definition.

#### Example:

```cpp
#include <iostream>
using namespace std;

class Box {
    private:
        int length;

    public:
        void setLength(int l); // Function declared inside class
        int getLength();       // Function declared inside class
};

// Function definitions outside the class
void Box::setLength(int l) {
    length = l;
}

int Box::getLength() {
    return length;
}

int main() {
    Box box;
    box.setLength(10);
    cout << "Box length: " << box.getLength() << endl;
    return 0;
}

```

---

### **3. Accessing Static Members of a Class**

Static members belong to the class rather than any object. Use the `::` operator with the class name to access them.

#### Example:

```cpp
class Counter {
    public:
        static int count; // Static member

        Counter() {
            count++;
        }
};

int Counter::count = 0; // Define and initialize static member

int main() {
    Counter c1, c2, c3;
    cout << "Count: " << Counter::count << endl; // Access static member
    return 0;
}

```

---

### **4. Resolving Ambiguity in Multiple Inheritance**

When two base classes have members with the same name, the `::` operator is used to specify which base class's member to access.

#### Example:

```cpp
#include <iostream>
using namespace std;

class Base1 {
    public:
        void show() {
            cout << "Base1::show()" << endl;
        }
};

class Base2 {
    public:
        void show() {
            cout << "Base2::show()" << endl;
        }
};

class Derived : public Base1, public Base2 {
};

int main() {
    Derived d;
    d.Base1::show(); // Specify which base class to use
    d.Base2::show();
    return 0;
}

```

---

### **5. Accessing Namespace Members**

The `::` operator is used to access members of a namespace explicitly.

#### Example:

```cpp
#include <iostream>

namespace Space1 {
    int value = 10;
}

namespace Space2 {
    int value = 20;
}

int main() {
    cout << "Space1 value: " << Space1::value << endl;
    cout << "Space2 value: " << Space2::value << endl;
    return 0;
}

```

---

### **6. Accessing Class Constructors in Derived Classes**

In derived classes, you can use `::` to call a base class's constructor explicitly.

#### Example:

```cpp
#include <iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Base constructor called" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() : Base() { // Explicitly call Base constructor
            cout << "Derived constructor called" << endl;
        }
};

int main() {
    Derived d;
    return 0;
}

```

---

### **7. Accessing Enclosed Enumerations**

The `::` operator can be used to access specific enumerators within a class or namespace.

#### Example:

```cpp
class Status {
    public:
        enum State { ACTIVE, INACTIVE };
};

int main() {
    cout << "Active: " << Status::ACTIVE << endl;
    cout << "Inactive: " << Status::INACTIVE << endl;
    return 0;
}

```

---

### **8. Accessing Overridden Methods in Inheritance**

The `::` operator is used to call a base class's version of an overridden method in a derived class.

#### Example:

```cpp
#include <iostream>
using namespace std;

class Base {
    public:
        void display() {
            cout << "Base display" << endl;
        }
};

class Derived : public Base {
    public:
        void display() {
            cout << "Derived display" << endl;
        }

        void showBaseDisplay() {
            Base::display(); // Call the base class method
        }
};

int main() {
    Derived d;
    d.display();
    d.showBaseDisplay();
    return 0;
}

```

---

### **9. Accessing Global Functions Hidden by Local or Member Functions**

When a global function has the same name as a local or member function, the `::` operator can access the global version.

#### Example:

```cpp
#include <iostream>
using namespace std;

void display() {
    cout << "Global display function" << endl;
}

class MyClass {
    public:
        void display() {
            cout << "Member display function" << endl;
        }

        void callGlobalDisplay() {
            ::display(); // Access global function
        }
};

int main() {
    MyClass obj;
    obj.display();
    obj.callGlobalDisplay();
    return 0;
}

```

---
