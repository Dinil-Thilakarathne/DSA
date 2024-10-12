- [1. How Jump Search Works](#1-how-jump-search-works)
- [2. Example](#2-example)
- [3. Algorithm for Jump Search](#3-algorithm-for-jump-search)
- [4. Complexity of Jump Search](#4-complexity-of-jump-search)
- [5. Implementation of Jump Search in C](#5-implementation-of-jump-search-in-c)
- [6. When to Use Jump Search](#6-when-to-use-jump-search)

Jump Search is an efficient search algorithm for sorted arrays. It improves on Linear Search by skipping ahead in steps, making it quicker to locate an element in large datasets. Here’s a breakdown of how Jump Search works, including its algorithm, complexity, and some sample code.

## 1. How Jump Search Works
1. **Step Size Calculation**:
   - The step size is generally the square root of the array's length. This minimizes the number of steps required to locate the target element.
   - For an array of length \( n \), the step size is \( m = \sqrt{n} \).

2. **Jumping Through the Array**:
   - Start at the beginning and move forward by the step size.
   - After each jump, check if the current element is greater than or equal to the target element.
   - If the current element is greater than the target, it means the target lies within the previous block, so a Linear Search is performed within that block.

3. **Linear Search Within the Block**:
   - Perform a Linear Search in the block where the target element might be located, which is the block between the last jump and the current jump position.

4. **End Condition**:
   - If you reach the end of the array and haven't found the element, it is not in the array.

## 2. Example
Consider the sorted array: `[1, 3, 5, 7, 9, 11, 13, 15, 17, 19]`
Target element: `15`
Array length \( n = 10 \)
Step size \( m = \sqrt{10} \approx 3 \)

1. **First Jump**: Start at index `0`. Jump to index `3` (element `7`).
2. **Second Jump**: From index `3`, jump to index `6` (element `13`).
3. **Third Jump**: From index `6`, jump to index `9` (element `19`).
4. Since `19` is greater than `15`, perform a **Linear Search** within the previous block (from index `6` to `9`).
5. Check index `7`, where you find `15`. The target is located.

## 3. Algorithm for Jump Search
Here's the pseudocode for Jump Search:

```plaintext
function jumpSearch(array, x):
    n = length(array)
    step = sqrt(n)
    prev = 0

    // Find the block where the element may be present
    while array[min(step, n)-1] < x:
        prev = step
        step += sqrt(n)
        if prev >= n:
            return -1 // Element not found

    // Perform Linear Search within the block
    for i from prev to min(step, n):
        if array[i] == x:
            return i

    return -1 // Element not found
```

## 4. Complexity of Jump Search
- **Time Complexity**: \( O(\sqrt{n}) \)
  - In the worst case, you’ll need to make \( \sqrt{n} \) jumps, and within each block, a maximum of \( \sqrt{n} \) comparisons is required.
- **Space Complexity**: \( O(1) \)
  - Jump Search does not require any extra space, only a fixed amount of additional storage for variables.

## 5. Implementation of Jump Search in C
Here’s how you might implement Jump Search in C:

```c
#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    // Jumping to the block where the element may be present
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Element not found
        }
    }

    // Perform a linear search in the block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1; // Element not found
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int x = 15;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, n, x);

    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element %d not found\n", x);
    }

    return 0;
}
```

## 6. When to Use Jump Search
Jump Search is ideal for:
- **Large Sorted Arrays**: It performs well with large sorted arrays and provides a significant speedup compared to Linear Search.
- **No Random Access Requirement**: Unlike Binary Search, Jump Search does not require random access to data, making it useful for data structures where direct indexing is inefficient or impractical.

However, for **unsorted arrays**, Jump Search is not applicable; for these cases, Linear Search is required. If the data is sorted, Jump Search is a great alternative, especially if Binary Search is not suitable.
