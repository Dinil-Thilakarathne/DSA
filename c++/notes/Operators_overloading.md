- [C++ Operators overloading](#c-operators-overloading)
  - [**Key Features of Operator Overloading**](#key-features-of-operator-overloading)
  - [**Syntax for Operator Overloading**](#syntax-for-operator-overloading)
    - [**Member Function Syntax**](#member-function-syntax)
    - [**Friend Function Syntax**](#friend-function-syntax)
  - [**1. Overloading Unary Operators**](#1-overloading-unary-operators)
  - [**2. Overloading Binary Operators**](#2-overloading-binary-operators)
  - [**3. Overloading Special Operators**](#3-overloading-special-operators)
    - [**Comparison of the Types**](#comparison-of-the-types)
  - [**1. Overloading `+` for Adding Two Objects**](#1-overloading--for-adding-two-objects)
  - [**2. Overloading `==` for Comparing Objects**](#2-overloading--for-comparing-objects)
  - [**3. Overloading `<<` for Printing**](#3-overloading--for-printing)
  - [**Rules and Limitations**](#rules-and-limitations)
  - [**Use Cases of Operator Overloading**](#use-cases-of-operator-overloading)

# C++ Operators overloading

**Operator overloading** in C++ allows you to define or alter the behavior of operators (such as `+`, `-`, `*`, `==`, etc.) for user-defined types (e.g., classes or structs). It enables operators to work with objects in a way that is intuitive and similar to built-in types.

---

## **Key Features of Operator Overloading**

1. **Customization**: You can redefine how operators work for your custom types.
2. **Syntax Consistency**: Enables objects of custom classes to use operators like built-in types.
3. **Member or Friend Function**: Operators can be overloaded as member functions or friend functions.
4. **Limitations**:
    - Only existing operators can be overloaded.
    - The precedence and associativity of operators cannot be changed.
    - Certain operators (`::`, `.*`, `.`, `sizeof`) cannot be overloaded.

---

## **Syntax for Operator Overloading**

The keyword `operator` is used followed by the operator symbol.

### **Member Function Syntax**

```cpp
class ClassName {
public:
    ReturnType operator Symbol(Parameters);
};

```

### **Friend Function Syntax**

```cpp
class ClassName {
    friend ReturnType operator Symbol(const ClassName&, Parameters);
};

```

---

There are three main types of operator overloading in C++:

## **1. Overloading Unary Operators**

Unary operators operate on a single operand. Examples include `+`, `-`, `++`, `--`, `!`, etc.

#### Example: Overloading `++` (Prefix Increment)

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    // Overload prefix ++ operator as a member function
    Counter& operator++() {
        ++value; // Increment the value
        return *this;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c1(5);

    ++c1; // Calls the overloaded ++ operator
    c1.display();

    return 0;
}

```

**Output:**

```
Value: 6

```

---

## **2. Overloading Binary Operators**

Binary operators operate on two operands. Examples include `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `&&`, `||`, etc.

#### Example: Overloading `+` (Addition)

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator as a member function
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.5, 3.0), c2(1.5, 4.5);

    Complex c3 = c1 + c2; // Calls the overloaded + operator
    c3.display();

    return 0;
}

```

**Output:**

```
4 + 7.5i

```

---

## **3. Overloading Special Operators**

Special operators include stream operators (`<<`, `>>`), array subscript operator (`[]`), function call operator (`()`), dereference operator (`*`), etc.

#### Example: Overloading `<<` (Stream Insertion)

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    // Overload << operator as a friend function
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main() {
    Point p1(3, 7);

    cout << "Point: " << p1 << endl; // Calls the overloaded << operator

    return 0;
}

```

**Output:**

```
Point: (3, 7)

```

---

### **Comparison of the Types**

| **Type** | **Description** | **Example** |
| --- | --- | --- |
| **Unary Operators** | Operate on a single operand. | `++`, `--`, `!`, etc. |
| **Binary Operators** | Operate on two operands. | `+`, `-`, `*`, `/`, etc. |
| **Special Operators** | Include stream operators, array subscripts, and function calls. | `<<`, `>>`, `[]`, `()` |

---

#### **Example: Operator Overloading**

## **1. Overloading `+` for Adding Two Objects**

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator as a member function
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.3, 4.5), c2(1.2, 3.4);

    Complex c3 = c1 + c2; // Calls the overloaded + operator
    c3.display();

    return 0;
}

```

**Output:**

```
3.5 + 7.9i

```

---

## **2. Overloading `==` for Comparing Objects**

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int length, width, height;

public:
    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    // Overload == operator
    bool operator==(const Box& other) {
        return length == other.length && width == other.width && height == other.height;
    }
};

int main() {
    Box box1(10, 20, 30), box2(10, 20, 30), box3(15, 25, 35);

    if (box1 == box2)
        cout << "Box1 is equal to Box2" << endl;
    else
        cout << "Box1 is not equal to Box2" << endl;

    if (box1 == box3)
        cout << "Box1 is equal to Box3" << endl;
    else
        cout << "Box1 is not equal to Box3" << endl;

    return 0;
}

```

**Output:**

```
Box1 is equal to Box2
Box1 is not equal to Box3

```

---

## **3. Overloading `<<` for Printing**

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    // Overload << operator as a friend function
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main() {
    Point p(5, 10);
    cout << "Point: " << p << endl;

    return 0;
}

```

**Output:**

```
Point: (5, 10)

```

---

## **Rules and Limitations**

1. **Operators That Cannot Be Overloaded**:
    - `::` (scope resolution operator)
    - `.` (member access operator)
    - `.*` (pointer-to-member operator)
    - `sizeof` (size of an object or type)
    - `typeid` (type information)
2. **Preserving Operator Precedence**:
    - The precedence and associativity of operators are fixed and cannot be altered through overloading.
3. **At Least One Operand Must Be a User-Defined Type**:
    - You cannot overload an operator for two built-in types.

---

## **Use Cases of Operator Overloading**

1. **Mathematical Operations**: E.g., adding two complex numbers or vectors.
2. **Comparison Operations**: E.g., comparing two objects (`==`, `<`, `>`).
3. **Stream Handling**: E.g., overloading `<<` and `>>` for input/output.
4. **Custom Classes**: E.g., defining operations for custom data structures like matrices, fractions, etc.
