- [1. How Linear Search Works:](#1-how-linear-search-works)
  - [1.1. Example](#11-example)
- [2. Pseudocode](#2-pseudocode)
- [3. Implementation in C](#3-implementation-in-c)
- [4. Complexity Analysis](#4-complexity-analysis)
- [5. Key Points](#5-key-points)

Linear search is the simplest searching algorithm that sequentially checks each element of the array or list until it finds the target element or reaches the end of the list. It is effective for small and unsorted datasets but is generally inefficient for larger datasets due to its linear time complexity.

## 1. How Linear Search Works:
1. **Start from the First Element**: Begin at the start of the array.
2. **Compare Each Element**: Compare the target element with each element in the array sequentially.
3. **Stop When Found or End is Reached**: If the element matches the target, the search is complete. If the end of the array is reached without finding the element, the target is not in the array.

### 1.1. Example
Given an array: `[3, 5, 2, 9, 6]`, and a target `9`:
- Start from the first element: `3` (no match).
- Move to the next element: `5` (no match).
- Continue to `2` (no match), then to `9`.
- Since `9` matches the target, the search is complete.

## 2. Pseudocode
Here’s a simple pseudocode for a linear search:

```plaintext
function linearSearch(arr, target):
    for each element in arr:
        if element == target:
            return index of element
    return -1  // Target not found
```

## 3. Implementation in C

```c
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target
        }
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {3, 5, 2, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
```

## 4. Complexity Analysis
- **Time Complexity**: \(O(n)\) — where \(n\) is the number of elements in the array, because each element is checked one by one.
- **Space Complexity**: \(O(1)\) — constant space, since it doesn’t require extra storage aside from the input array.

## 5. Key Points
- Linear search is **inefficient** for large datasets, as it requires examining each element.
- It works for both **sorted and unsorted** lists, making it versatile but slow.
- It is useful for **small datasets** or when the array is not sorted.

Linear search is fundamental in computer science and often serves as a baseline for comparing the performance of other search algorithms.
