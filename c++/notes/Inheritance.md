- [C++ Inheritance](#c-inheritance)
- [**Inheritance in C++**](#inheritance-in-c)
    - [**Key Features**](#key-features)
  - [**Types of Inheritance**](#types-of-inheritance)
    - [**Access Specifiers in Inheritance**](#access-specifiers-in-inheritance)
  - [**Virtual Inheritance**](#virtual-inheritance)
  - [**Advantages of Inheritance**](#advantages-of-inheritance)
  - [**Disadvantages of Inheritance**](#disadvantages-of-inheritance)
  - [**Modes of Inheritance in C++**](#modes-of-inheritance-in-c)
    - [**Public Inheritance**](#public-inheritance)
    - [**Protected Inheritance**](#protected-inheritance)
    - [**Private Inheritance**](#private-inheritance)
    - [**Comparison Table**](#comparison-table)
    - [**Summary of Use Cases**](#summary-of-use-cases)
  - [**Inheriting Constructors in C++**](#inheriting-constructors-in-c)
    - [**Key Points About Inheriting Constructors**](#key-points-about-inheriting-constructors)
    - [**Rules and Limitations**](#rules-and-limitations)
    - [**When to Use Inheriting Constructors**](#when-to-use-inheriting-constructors)
  - [**The Diamond Problem in C++**](#the-diamond-problem-in-c)
    - [**Explanation**](#explanation)
    - [**Diagram**](#diagram)
    - [**Solutions to the Diamond Problem**](#solutions-to-the-diamond-problem)
    - [**1. Virtual Inheritance**](#1-virtual-inheritance)
    - [**2. Explicit Qualification**](#2-explicit-qualification)
    - [**When to Use Virtual Inheritance**](#when-to-use-virtual-inheritance)

# C++ Inheritance

# **Inheritance in C++**

Inheritance is an **object-oriented programming (OOP)** concept that allows a class (called the **derived class**) to inherit properties and behaviors (data members and member functions) from another class (called the **base class**). This promotes **code reuse** and provides a way to implement hierarchical relationships.

---

### **Key Features**

1. **Base Class**: The class whose members are inherited.
2. **Derived Class**: The class that inherits members from the base class.
3. **Access Modifiers**: Control the visibility of the base class members in the derived class (`public`, `protected`, `private`).
4. **Hierarchical Levels**: A derived class can itself act as a base class.

---

**Syntax**

```cpp
class BaseClass {
    // Base class members
};

class DerivedClass : accessSpecifier BaseClass {
    // Derived class members
};

```

**Example: Simple Inheritance**

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "I can eat." << endl;
    }

    void sleep() {
        cout << "I can sleep." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();    // Inherited from Animal
    dog.sleep();  // Inherited from Animal
    dog.bark();   // Defined in Dog
    return 0;
}

```

**Output:**

```
I can eat.
I can sleep.
I can bark.

```

---

## **Types of Inheritance**

1. **Single Inheritance**:
A single derived class inherits from one base class.

    ```cpp
    class B : public A { };

    ```

2. **Multiple Inheritance**:
A derived class inherits from more than one base class.

    ```cpp
    class C : public A, public B { };

    ```

3. **Multilevel Inheritance**:
A derived class is derived from another derived class.

    ```cpp
    class B : public A { };
    class C : public B { };

    ```

4. **Hierarchical Inheritance**:
Multiple derived classes inherit from a single base class.

    ```cpp
    class B : public A { };
    class C : public A { };

    ```

5. **Hybrid Inheritance**:
A combination of two or more types of inheritance.

---

### **Access Specifiers in Inheritance**

The access specifier determines how base class members are inherited:

| **Base Class Member** | **public inheritance** | **protected inheritance** | **private inheritance** |
| --- | --- | --- | --- |
| `public` | public | protected | private |
| `protected` | protected | protected | private |
| `private` | Not accessible | Not accessible | Not accessible |

---

**Example: Protected Inheritance**

```cpp
#include <iostream>
using namespace std;

class Parent {
protected:
    int protectedValue;

public:
    Parent(int val) : protectedValue(val) {}
};

class Child : protected Parent {
public:
    Child(int val) : Parent(val) {}

    void display() {
        cout << "Protected value: " << protectedValue << endl;
    }
};

int main() {
    Child c(42);
    c.display();
    return 0;
}

```

---

## **Virtual Inheritance**

Virtual inheritance is used to prevent **diamond problem** in multiple inheritance, where a derived class inherits from multiple base classes having a common ancestor.

Example:

```cpp
class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.display(); // No ambiguity due to virtual inheritance
    return 0;
}

```

---

## **Advantages of Inheritance**

1. **Code Reusability**: Promotes the reuse of existing code.
2. **Scalability**: Helps build scalable systems by defining common behaviors in base classes.
3. **Extensibility**: Easily add or modify features in derived classes.

---

## **Disadvantages of Inheritance**

1. **Complexity**: Multiple or hybrid inheritance can increase code complexity.
2. **Tight Coupling**: Base and derived classes become tightly coupled.
3. **Overhead**: Derived classes can inherit unnecessary members, increasing memory usage.

---

## **Modes of Inheritance in C++**

Modes of inheritance define how the members (variables and functions) of the base class are inherited by the derived class. They are specified using the **access specifiers**:

1. **Public Inheritance**
2. **Protected Inheritance**
3. **Private Inheritance**

---

### **Public Inheritance**

- **Definition**: The `public` members of the base class remain `public` in the derived class, and the `protected` members of the base class remain `protected` in the derived class.
- **When to Use**: Use `public` inheritance when the derived class **is-a** type of the base class (e.g., a `Car` is a `Vehicle`).

**Member Access:**

| Base Class | Access in Derived Class |
| --- | --- |
| `public` | `public` |
| `protected` | `protected` |
| `private` | Not Accessible |

**Example:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void showPublic() {
        cout << "Public function in Base" << endl;
    }

protected:
    void showProtected() {
        cout << "Protected function in Base" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        showPublic();     // Accessible
        showProtected();  // Accessible
    }
};

int main() {
    Derived obj;
    obj.showPublic(); // Accessible
    // obj.showProtected(); // Error: Cannot access protected member
    obj.display();
    return 0;
}

```

---

### **Protected Inheritance**

- **Definition**: The `public` and `protected` members of the base class become `protected` in the derived class.
- **When to Use**: Use `protected` inheritance when the derived class needs to reuse the base class’s functionality but should not expose it to the outside world.

**Member Access:**

| Base Class | Access in Derived Class |
| --- | --- |
| `public` | `protected` |
| `protected` | `protected` |
| `private` | Not Accessible |

**Example:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void showPublic() {
        cout << "Public function in Base" << endl;
    }

protected:
    void showProtected() {
        cout << "Protected function in Base" << endl;
    }
};

class Derived : protected Base {
public:
    void display() {
        showPublic();     // Accessible
        showProtected();  // Accessible
    }
};

int main() {
    Derived obj;
    // obj.showPublic(); // Error: Not accessible due to protected inheritance
    obj.display();
    return 0;
}

```

---

### **Private Inheritance**

- **Definition**: The `public` and `protected` members of the base class become `private` in the derived class.
- **When to Use**: Use `private` inheritance when the derived class wants to use the base class’s functionality internally but does not want to expose the base class’s interface to the outside world.

**Member Access:**

| Base Class | Access in Derived Class |
| --- | --- |
| `public` | `private` |
| `protected` | `private` |
| `private` | Not Accessible |

**Example:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void showPublic() {
        cout << "Public function in Base" << endl;
    }

protected:
    void showProtected() {
        cout << "Protected function in Base" << endl;
    }
};

class Derived : private Base {
public:
    void display() {
        showPublic();     // Accessible
        showProtected();  // Accessible
    }
};

int main() {
    Derived obj;
    // obj.showPublic(); // Error: Not accessible due to private inheritance
    obj.display();
    return 0;
}

```

---

### **Comparison Table**

| **Access Modifier in Base Class** | **Public Inheritance** | **Protected Inheritance** | **Private Inheritance** |
| --- | --- | --- | --- |
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | Not Accessible | Not Accessible | Not Accessible |

---

### **Summary of Use Cases**

1. **Public Inheritance**:
    - Use when you want to express an "is-a" relationship.
    - Example: `Car` is-a `Vehicle`.
2. **Protected Inheritance**:
    - Use when you want to reuse functionality but prevent external access.
    - Example: Internal helper classes that should not expose their interface.
3. **Private Inheritance**:
    - Use when the relationship is more of a "has-a" or "implemented-in-terms-of."
    - Example: Using a `Base` class only to implement functionality in `Derived`.

---

## **Inheriting Constructors in C++**

In C++11 and later, constructors from a base class can be inherited by a derived class using the `using` keyword. This eliminates the need to redefine the base class constructors explicitly in the derived class, reducing boilerplate code.

---

### **Key Points About Inheriting Constructors**

1. **Automatic Inheritance**:
    - A derived class can inherit all constructors of the base class using `using BaseClassName::BaseClassName;`.
    - The inherited constructors directly call the base class's constructors.
2. **Overriding Inherited Constructors**:
    - You can define additional constructors in the derived class.
    - If a derived class has its own constructors, they won't override inherited constructors but will coexist.
3. **Default, Copy, and Move Constructors**:
    - Default, copy, and move constructors of the base class are also inherited unless explicitly overridden.
4. **Access Specifiers**:
    - Only accessible constructors from the base class are inherited.
5. **Customization**:
    - Inherited constructors cannot be customized in the derived class.

---

**Syntax**

```cpp
class Base {
public:
    Base(int x) { /* ... */ }
    Base(int x, int y) { /* ... */ }
};

class Derived : public Base {
    using Base::Base; // Inherit Base's constructors
};

```

---

**Example: Simple Constructor Inheritance**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) {
        cout << "Base class constructor called with value: " << x << endl;
    }
};

class Derived : public Base {
    using Base::Base; // Inheriting Base class constructors
};

int main() {
    Derived d(42); // Calls Base(int)
    return 0;
}

```

**Output:**

```
Base class constructor called with value: 42

```

---

**Example: Inheriting Multiple Constructors**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base default constructor called!" << endl;
    }

    Base(int x) {
        cout << "Base parameterized constructor called with value: " << x << endl;
    }
};

class Derived : public Base {
    using Base::Base; // Inherit both constructors
};

int main() {
    Derived d1;    // Calls Base()
    Derived d2(10); // Calls Base(int)
    return 0;
}

```

**Output:**

```
Base default constructor called!
Base parameterized constructor called with value: 10

```

---

**Example: Adding Additional Constructors**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) {
        cout << "Base constructor called with value: " << x << endl;
    }
};

class Derived : public Base {
    using Base::Base; // Inherit Base class constructors

public:
    Derived(double y) : Base(static_cast<int>(y)) {
        cout << "Derived constructor called with value: " << y << endl;
    }
};

int main() {
    Derived d1(42);      // Calls Base(int)
    Derived d2(42.5);    // Calls Derived(double) -> Base(int)
    return 0;
}

```

**Output:**

```
Base constructor called with value: 42
Base constructor called with value: 42
Derived constructor called with value: 42.5

```

---

### **Rules and Limitations**

1. **Ambiguity**:
    - If the derived class introduces a constructor with the same signature as one of the inherited constructors, ambiguity occurs.
    - Example:

    This will result in a **compiler error**.

        ```cpp
        class Base {
        public:
            Base(int x) {}
        };

        class Derived : public Base {
            using Base::Base; // Inherit Base(int)
        public:
            Derived(int x) {} // Ambiguity: Two constructors with same signature
        };

        ```

2. **Private Base Constructors**:
    - Constructors in the `private` section of the base class are not inherited.
    - Attempting to access them will result in a **compiler error**.
3. **Multiple Base Classes**:
    - If a derived class has multiple base classes, you can inherit constructors from all base classes individually using `using`.

---

### **When to Use Inheriting Constructors**

1. **Reduces Boilerplate**:
    - Useful when the derived class doesn't need to define its own constructors and can rely on the base class's constructors.
2. **Consistency**:
    - Ensures derived classes behave consistently with their base classes.
3. **Simplifies Maintenance**:
    - Any changes to the base class constructors are automatically reflected in derived classes.

---

## **The Diamond Problem in C++**

The **diamond problem** arises in multiple inheritance when a class inherits from two classes that share a common base class. It leads to ambiguity and redundancy in the inheritance hierarchy.

---

### **Explanation**

1. **Structure**:
    - A base class (let's call it `Base`) is inherited by two intermediate classes (`Derived1` and `Derived2`).
    - A new class (`Final`) inherits from both `Derived1` and `Derived2`.
2. **Ambiguity**:
    - When `Final` tries to access a member of `Base`, it doesn't know whether to use the copy from `Derived1` or `Derived2`.
3. **Redundancy**:
    - If `Base` contains data members, `Final` inherits two separate copies of them, leading to inefficiency and inconsistency.

---

### **Diagram**

Here's a visual representation of the diamond problem:

```
        Base
       /    \
  Derived1  Derived2
       \     /
        Final

```

---

**Example**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class function called." << endl;
    }
};

class Derived1 : public Base {};

class Derived2 : public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;
    obj.display(); // Ambiguity: Which 'Base' should be used?
    return 0;
}

```

**Error:**

```
error: request for member ‘display’ is ambiguous

```

The compiler cannot determine whether `display` should be called from `Derived1` or `Derived2`.

---

### **Solutions to the Diamond Problem**

### **1. Virtual Inheritance**

C++ solves the diamond problem using **virtual inheritance**. By making the intermediate classes (`Derived1` and `Derived2`) inherit `Base` virtually, the `Final` class gets a single shared instance of `Base`.

**Modified Example Using Virtual Inheritance:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class function called." << endl;
    }
};

class Derived1 : virtual public Base {};

class Derived2 : virtual public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;
    obj.display(); // Unambiguous: Only one instance of 'Base'
    return 0;
}

```

**Output:**

```
Base class function called.

```

**Key Point:**

- With `virtual` inheritance, `Base` is included only once in the inheritance hierarchy, regardless of how many times it's inherited.

---

### **2. Explicit Qualification**

Without `virtual` inheritance, you can explicitly specify which path to use when accessing `Base`.

**Example with Explicit Qualification:**

```cpp
class Base {
public:
    void display() {
        cout << "Base class function called." << endl;
    }
};

class Derived1 : public Base {};

class Derived2 : public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;
    obj.Derived1::display(); // Specify Derived1's Base
    obj.Derived2::display(); // Specify Derived2's Base
    return 0;
}

```

**Output:**

```
Base class function called.
Base class function called.

```

---

### **When to Use Virtual Inheritance**

- **Avoid Redundancy:** Prevents multiple copies of the same base class.
- **Prevent Ambiguity:** Ensures only one instance of the base class exists in the derived class.
- **Large Hierarchies:** Especially useful in complex inheritance hierarchies to maintain clarity.

---

Let me know if you’d like a deeper dive into any aspect or related topics!
