- [C++ Dynamic memory allocation](#c-dynamic-memory-allocation)
  - [**1. How Dynamic Memory Allocation Works**](#1-how-dynamic-memory-allocation-works)
  - [**2. The `new` Operator**](#2-the-new-operator)
    - [**Syntax:**](#syntax)
    - [**Example:**](#example)
    - [Allocating a Single Object:](#allocating-a-single-object)
    - [Allocating an Array:](#allocating-an-array)
  - [**3. The `delete` Operator**](#3-the-delete-operator)
    - [**Syntax:**](#syntax-1)
    - [**Key Notes:**](#key-notes)
  - [**4. Example: Dynamic Memory Allocation for Objects**](#4-example-dynamic-memory-allocation-for-objects)
    - [Example:](#example-1)
  - [**5. Key Features of `new` and `delete`**](#5-key-features-of-new-and-delete)
  - [**6. Common Issues**](#6-common-issues)
    - [**Memory Leaks:**](#memory-leaks)
    - [Example of Memory Leak:](#example-of-memory-leak)
    - [**Dangling Pointers:**](#dangling-pointers)
    - [Example of Dangling Pointer:](#example-of-dangling-pointer)
  - [**7. Best Practices**](#7-best-practices)

# C++ Dynamic memory allocation

In C++, **dynamic memory allocation** refers to allocating memory during the program's runtime, as opposed to compile-time (static memory allocation). This is especially useful when the size of the data structures (e.g., arrays, objects) isn't known at compile time. Dynamic memory allocation in C++ is achieved using the `new` and `delete` operators.

---

## **1. How Dynamic Memory Allocation Works**

- When you use the `new` operator, the requested memory is allocated from the **heap** (also known as free store), a region of memory reserved for dynamic allocation.
- The `new` operator returns a pointer to the allocated memory.
- When the allocated memory is no longer needed, it must be freed using the `delete` operator to prevent **memory leaks**.

---

## **2. The `new` Operator**

The `new` operator allocates memory for a single object or an array of objects.

### **Syntax:**

```cpp
pointer = new data_type;          // Allocates memory for a single object
pointer = new data_type[size];    // Allocates memory for an array of objects

```

### **Example:**

### Allocating a Single Object:

```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = new int;  // Allocate memory for a single integer
    *p = 42;           // Assign value to the dynamically allocated memory
    cout << "Value: " << *p << endl;

    delete p;          // Free the allocated memory
    return 0;
}

```

### Allocating an Array:

```cpp
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // Allocate memory for an array of 5 integers

    // Assign values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // Print values
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free the allocated memory
    return 0;
}

```

---

## **3. The `delete` Operator**

The `delete` operator deallocates memory allocated by `new` and releases it back to the heap.

### **Syntax:**

```cpp
delete pointer;        // For a single object
delete[] pointer;      // For an array of objects

```

### **Key Notes:**

- Always pair `delete` with `new` to avoid memory leaks.
- Use `delete[]` for arrays allocated with `new[]`.

---

## **4. Example: Dynamic Memory Allocation for Objects**

You can also dynamically allocate memory for user-defined types (e.g., objects of a class).

### Example:

```cpp
#include <iostream>
using namespace std;

class Box {
    public:
        int length;

        Box(int l) : length(l) {
            cout << "Box created with length " << length << endl;
        }

        ~Box() {
            cout << "Box destroyed with length " << length << endl;
        }
};

int main() {
    // Allocate a single object
    Box* b1 = new Box(10);

    // Allocate an array of objects
    Box* bArray = new Box[3]{{1}, {2}, {3}};

    // Free memory
    delete b1;
    delete[] bArray;

    return 0;
}

```

---

## **5. Key Features of `new` and `delete`**

- **Initialization:**
    - The `new` operator can initialize memory while allocating it.

        ```cpp
        int* p = new int(100);  // Allocate and initialize to 100

        ```

- **Exception Handling:**
    - If memory allocation fails, `new` throws a `std::bad_alloc` exception.
    - Use `nothrow` to avoid exceptions and instead return `nullptr` on failure:

        ```cpp
        int* p = new (nothrow) int;
        if (!p) {
            cout << "Memory allocation failed!" << endl;
        }

        ```


---

## **6. Common Issues**

### **Memory Leaks:**

If dynamically allocated memory is not freed with `delete`, it remains allocated until the program ends, consuming memory unnecessarily.

### Example of Memory Leak:

```cpp
int* p = new int(42);
// Forgot to delete p

```

### **Dangling Pointers:**

If a pointer is used after the memory it points to has been freed, it becomes a dangling pointer, leading to undefined behavior.

### Example of Dangling Pointer:

```cpp
int* p = new int(42);
delete p;   // Free memory
cout << *p; // Undefined behavior

```

---

## **7. Best Practices**

1. Always match `new` with `delete` and `new[]` with `delete[]`.
2. Set pointers to `nullptr` after freeing memory to avoid dangling pointers.

    ```cpp
    delete p;
    p = nullptr;

    ```

3. Prefer **smart pointers** (`std::unique_ptr`, `std::shared_ptr`, etc.) from the Standard Library to manage dynamic memory automatically.

---
