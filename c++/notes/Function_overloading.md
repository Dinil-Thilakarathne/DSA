- [C++ Function overloading](#c-function-overloading)
    - [**Key Points of Function Overloading**](#key-points-of-function-overloading)
  - [**Rules for Function Overloading**](#rules-for-function-overloading)
  - [**Use Cases of Function Overloading**](#use-cases-of-function-overloading)
  - [**Advantages**](#advantages)
  - [**Limitations**](#limitations)
  - [**Potential Ambiguities in Function Overloading**](#potential-ambiguities-in-function-overloading)
  - [**Advanced Use Cases of Function Overloading**](#advanced-use-cases-of-function-overloading)
    - [**1. Overloading for Different Types**](#1-overloading-for-different-types)
    - [**2. Overloading for Different Parameter Orders**](#2-overloading-for-different-parameter-orders)
    - [**3. Function Overloading with References**](#3-function-overloading-with-references)
    - [**4. Combining Overloading with Templates**](#4-combining-overloading-with-templates)
  - [**Best Practices for Avoiding Ambiguities**](#best-practices-for-avoiding-ambiguities)

# C++ Function overloading

**Function overloading** in C++ is a feature that allows multiple functions to have the **same name** but differ in their **parameter lists**. The compiler differentiates these functions based on the number and types of arguments passed during a function call.

---

### **Key Points of Function Overloading**

1. **Same Name**: Functions share the same name but must have different parameter lists (signature).
2. **Parameter List**: The distinction is made based on:
    - Number of parameters.
    - Types of parameters.
    - Order of parameters.
3. **Return Type**: The return type is **not considered** for overloading. Functions must differ in parameters.

---

#### **Syntax of Function Overloading**

```cpp
class Example {
public:
    void display(int a);        // Function 1
    void display(double b);     // Function 2
    void display(int a, int b); // Function 3
};

```

---

#### **Example of Function Overloading**

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    cout << "Add two integers: " << calc.add(5, 10) << endl;
    cout << "Add two doubles: " << calc.add(2.5, 3.5) << endl;
    cout << "Add three integers: " << calc.add(1, 2, 3) << endl;

    return 0;
}

```

**Output:**

```
Add two integers: 15
Add two doubles: 6
Add three integers: 6

```

---

## **Rules for Function Overloading**

1. **Valid Parameter Differences**:
    - Varying the number of parameters.
    - Changing the type of parameters.
    - Changing the sequence of parameters for different types.
2. **Return Type Doesn't Matter**:
    - Functions cannot be overloaded solely based on the return type.

#### Invalid Example:

```cpp
int calculate(int x);
double calculate(int x); // Error: Cannot differ by return type alone

```

---

## **Use Cases of Function Overloading**

1. **Math Operations**: Different types of addition, multiplication, etc., for integers, floats, and doubles.
2. **Printing Data**: Displaying different data types or formats.
3. **File Handling**: Opening files using different modes or sources (e.g., path, URL, etc.).

---

## **Advantages**

- Improves **readability** and **reusability** of code.
- Reduces the need for uniquely named functions that perform similar tasks.
- Helps implement polymorphism in a simpler form.

---

## **Limitations**

1. **Ambiguity**: Overloading can lead to ambiguity if the compiler cannot resolve which version to use.

    ```cpp
    void show(int a);
    void show(float a);

    show(5); // Ambiguity: Is 5 an int or float?

    ```

2. **Cannot Overload Based on Return Type Alone**.

---

## **Potential Ambiguities in Function Overloading**

Ambiguities arise in function overloading when the compiler cannot determine which overloaded function to call. These situations occur due to implicit type conversions or when multiple functions match the arguments equally well.

---

#### **Example 1: Ambiguity with Implicit Type Conversion**

```cpp
#include <iostream>
using namespace std;

void display(int a) {
    cout << "Integer: " << a << endl;
}

void display(double a) {
    cout << "Double: " << a << endl;
}

int main() {
    display(5);      // Calls display(int)
    display(5.5);    // Calls display(double)
    display('A');    // Ambiguity: 'A' can be converted to int or double
    return 0;
}

```

**Explanation:**

- For `display('A')`, `'A'` (a char) can be implicitly converted to both `int` and `double`. The compiler reports ambiguity.

---

#### **Example 2: Ambiguity with Default Arguments**

```cpp
#include <iostream>
using namespace std;

void show(int a, int b = 0) {
    cout << "Two integers: " << a << ", " << b << endl;
}

void show(int a) {
    cout << "One integer: " << a << endl;
}

int main() {
    show(5);  // Ambiguity: Both functions match this call
    return 0;
}

```

**Explanation:**

- `show(5)` matches both `show(int)` and `show(int, int)` due to the default argument in `show(int, int)`.

---

#### **Example 3: Ambiguity with Function Pointers**

```cpp
#include <iostream>
using namespace std;

void calculate(int a) {
    cout << "Integer calculation: " << a * a << endl;
}

void calculate(float a) {
    cout << "Float calculation: " << a * a << endl;
}

int main() {
    void (*funcPtr)(float) = calculate; // Ambiguity: Which calculate to use?
    funcPtr(2.5);                      // Compiler error
    return 0;
}

```

**Explanation:**

- The function pointer `funcPtr` cannot resolve which version of `calculate` to use due to the presence of overloaded functions.

---

## **Advanced Use Cases of Function Overloading**

---

### **1. Overloading for Different Types**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Printer {
public:
    void print(int data) {
        cout << "Integer: " << data << endl;
    }

    void print(double data) {
        cout << "Double: " << data << endl;
    }

    void print(string data) {
        cout << "String: " << data << endl;
    }
};

int main() {
    Printer p;
    p.print(10);          // Calls print(int)
    p.print(3.14);        // Calls print(double)
    p.print("Hello!");    // Calls print(string)

    return 0;
}

```

---

### **2. Overloading for Different Parameter Orders**

```cpp
#include <iostream>
using namespace std;

void process(int a, char b) {
    cout << "Processing int and char: " << a << ", " << b << endl;
}

void process(char b, int a) {
    cout << "Processing char and int: " << b << ", " << a << endl;
}

int main() {
    process(10, 'A');  // Calls process(int, char)
    process('B', 20);  // Calls process(char, int)

    return 0;
}

```

---

### **3. Function Overloading with References**

```cpp
#include <iostream>
using namespace std;

void update(int& x) {
    x += 10;
    cout << "Integer updated: " << x << endl;
}

void update(double& x) {
    x *= 2;
    cout << "Double updated: " << x << endl;
}

int main() {
    int a = 5;
    double b = 3.14;

    update(a);  // Calls update(int&)
    update(b);  // Calls update(double&)

    return 0;
}

```

---

### **4. Combining Overloading with Templates**

```cpp
#include <iostream>
using namespace std;

template <typename T>
void display(T data) {
    cout << "Template version: " << data << endl;
}

void display(int data) {
    cout << "Non-template version: " << data << endl;
}

int main() {
    display(10);       // Calls non-template version
    display(3.14);     // Calls template version
    display("Hi!");    // Calls template version

    return 0;
}

```

---

## **Best Practices for Avoiding Ambiguities**

1. Avoid **default arguments** in overloaded functions.
2. Be explicit with **parameter types** to reduce the chances of implicit conversions.
3. Use **templates** when function overloading isn't sufficient for handling multiple types.
4. Use function pointers or lambdas carefully when overloaded functions are involved.
