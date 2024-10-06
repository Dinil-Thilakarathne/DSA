- [Key Features of Unions](#key-features-of-unions)
- [Union Declaration and Syntax](#union-declaration-and-syntax)
- [Accessing Union Members](#accessing-union-members)
- [Memory Size of a Union](#memory-size-of-a-union)
- [When to Use Unions](#when-to-use-unions)
- [Example of a Union in a Real-World Context](#example-of-a-union-in-a-real-world-context)

In C, a **union** is a data structure that, like a **structure**, can hold multiple data types. However, unlike structures where each member has its own storage, **all members of a union share the same memory location**. This means that a union can only store one of its members at a time.

## Key Features of Unions

1. **Shared Memory**: All members of a union share the same memory. The size of a union is determined by the size of its largest member.
2. **Single Value Storage**: Since all members occupy the same memory, only one member can store a value at any given time.
3. **Efficient Memory Usage**: Unions allow you to use a single memory location for multiple purposes, making them memory efficient when you only need to store one value from a set of different types.

## Union Declaration and Syntax

Declaring a union is similar to declaring a structure. You use the `union` keyword, followed by the union name and its members.

```c
union Data {
    int i;
    float f;
    char str[20];
};
```

In this example, `Data` is a union that can store either an integer (`i`), a float (`f`), or a string (`str`) of up to 20 characters.

## Accessing Union Members

You access members of a union using the dot (`.`) operator if you have a union variable, or the arrow (`->`) operator if you have a pointer to a union.

```c
#include <stdio.h>

int main() {
    union Data data;

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    snprintf(data.str, sizeof(data.str), "Hello");
    printf("data.str : %s\n", data.str);

    return 0;
}
```

In this example:
- We assign a value to `data.i` and print it.
- Then we assign a value to `data.f` and print it.
- Finally, we assign a string to `data.str` and print it.

Each time a new value is assigned to a different member, the previous value is **overwritten** because all members share the same memory location.

## Memory Size of a Union

The size of a union is the size of its largest member. For instance, if an integer is 4 bytes, a float is 4 bytes, and a character array of 20 characters is 20 bytes, then the union will allocate 20 bytes.

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    printf("Size of union Data : %lu\n", sizeof(data));
    return 0;
}
```

Output:
```
Size of union Data : 20
```

## When to Use Unions

Unions are useful when you want to use the same memory location for different purposes, and you know that you will only need to store one value at a time. Here are some typical use cases:

- **Memory Optimization**: When memory is limited, and you need a variable that can store different types at different times.
- **Variant Data Storage**: Unions are used in situations where data can come in different forms, such as in the representation of **variant data types**.
- **Embedded Systems**: Unions are commonly used in embedded programming to manipulate data at the bit or byte level.

## Example of a Union in a Real-World Context

Suppose you have a system where a sensor can provide different types of readings (e.g., integer and float readings), but only one type is available at a time:

```c
#include <stdio.h>

typedef union SensorData {
    int intValue;
    float floatValue;
} SensorData;

typedef struct Sensor {
    char type;  // 'i' for integer, 'f' for float
    SensorData data;
} Sensor;

int main() {
    Sensor sensor;

    // Integer sensor reading
    sensor.type = 'i';
    sensor.data.intValue = 42;
    if (sensor.type == 'i') {
        printf("Integer Reading: %d\n", sensor.data.intValue);
    }

    // Float sensor reading
    sensor.type = 'f';
    sensor.data.floatValue = 36.7f;
    if (sensor.type == 'f') {
        printf("Float Reading: %f\n", sensor.data.floatValue);
    }

    return 0;
}
```

In this example:
- The `Sensor` structure holds a `type` field that indicates the type of reading.
- The `data` field is a union `SensorData` that can store either an integer or a float.

By checking `sensor.type`, you can determine which type of reading to print, making efficient use of memory.

---

Unions are powerful tools for certain applications, especially where memory efficiency is critical or when you need to represent multiple data types at the same location. However, they require careful management to ensure you’re only accessing the correct member, as misuse can lead to **unpredictable behavior**.
