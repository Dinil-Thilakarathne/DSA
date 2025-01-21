- [C++ Friend functions](#c-friend-functions)
    - [**Key Characteristics of Friend Functions**](#key-characteristics-of-friend-functions)
    - [**Syntax**](#syntax)
  - [What is a friend function?](#what-is-a-friend-function)
  - [Why use a friend function?](#why-use-a-friend-function)
  - [How do you define and declare a friend function?](#how-do-you-define-and-declare-a-friend-function)
    - [**Example: Accessing Private Members**](#example-accessing-private-members)
    - [**Example: Overloading `<<` Operator Using Friend Function**](#example-overloading--operator-using-friend-function)
    - [**Advantages of Friend Functions**](#advantages-of-friend-functions)
    - [**Disadvantages of Friend Functions**](#disadvantages-of-friend-functions)
    - [**When to Use Friend Functions**](#when-to-use-friend-functions)

# C++ Friend functions

Module: SCS 1310 - OOP

A **friend function** in C++ is a function that is not a member of a class but has access to the private and protected members of the class. It is declared in the class using the keyword `friend`.

---

### **Key Characteristics of Friend Functions**

1. **Not a Member**: A friend function is not a member of the class, so it does not have a `this` pointer.
2. **Access**: It has access to the private and protected members of the class.
3. **Declaration**: Declared inside the class using the `friend` keyword but defined outside the class.
4. **Scope**: It is in the global or namespace scope, not within the class scope.

---

### **Syntax**

```cpp
class ClassName {
    friend ReturnType FriendFunctionName(Parameters);
};

```

---

## What is a friend function?

- A friend function is a function that is not a member of a class but is granted access to its private and protected members.

## Why use a friend function?

- Friend functions are useful when you need a function to operate on private data of a class but want to keep it non-member for modularity or external functionality.
- To provide an external function access to private/protected members.
- To allow non-member functions to work closely with a class.
- Useful in operator overloading, such as `<<` and `>>`.

## How do you define and declare a friend function?

- Declare the function inside the class with the friend keyword.
- Define it outside the class, similar to a regular function.

---

### **Example: Accessing Private Members**

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Declare friend function
    friend int getLength(const Box& b);
};

// Friend function definition
int getLength(const Box& b) {
    return b.length; // Accessing private member
}

int main() {
    Box box(10);
    cout << "Length of the box: " << getLength(box) << endl;
    return 0;
}

```

**Output:**

```
Length of the box: 10

```

---

### **Example: Overloading `<<` Operator Using Friend Function**

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    // Declare friend function
    friend ostream& operator<<(ostream& out, const Point& p);
};

// Friend function definition
ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1(5, 10);
    cout << "Point: " << p1 << endl; // Calls the overloaded << operator
    return 0;
}

```

**Output:**

```
Point: (5, 10)

```

---

### **Advantages of Friend Functions**

1. **Flexibility**: Provides an interface for external functions to access private/protected members.
2. **Operator Overloading**: Essential for overloading certain operators like `<<` and `>>`.
3. **Encapsulation**: Maintains encapsulation by limiting access to specific functions.

---

### **Disadvantages of Friend Functions**

1. **Coupling**: Can tightly couple the function to the class, reducing modularity.
2. **Encapsulation Violation**: It can break encapsulation if overused.
3. **Non-Member**: Cannot be called on an object like a member function.

---

### **When to Use Friend Functions**

1. When external functions need limited access to a class.
2. When overloading operators that are not members (e.g., `<<` and `>>`).
3. When the function logically doesn’t belong to the class but needs access to its members.

Let me know if you'd like more examples or a deeper dive into any specific part!
