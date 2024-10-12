- [1. How Binary Search Works:](#1-how-binary-search-works)
  - [1.1. Example](#11-example)
- [2. Pseudocode](#2-pseudocode)
- [3. Implementation in C](#3-implementation-in-c)
- [4. Complexity Analysis](#4-complexity-analysis)
- [5. Key Points](#5-key-points)

Binary search is a highly efficient algorithm for finding an element in a sorted array. Unlike linear search, which checks each element sequentially, binary search repeatedly divides the search interval in half, reducing the time complexity to \(O(\log n)\).

## 1. How Binary Search Works:
1. **Start with the Middle Element**: Begin by checking the middle element of the array.
2. **Compare**:
   - If the middle element is the target, the search is complete.
   - If the target is smaller than the middle element, narrow the search to the left half of the array.
   - If the target is larger than the middle element, narrow the search to the right half of the array.
3. **Repeat**: Repeat the process on the new subarray until the element is found or the subarray has zero length.

### 1.1. Example
Given a sorted array: `[2, 4, 7, 10, 12, 15, 20]`, and target `10`:
- First, check the middle element: `10` is compared with `10` in position 3.
- Since `10` matches, the search is complete.

## 2. Pseudocode
Here's the pseudocode for binary search:

```plaintext
function binarySearch(arr, target):
    left = 0
    right = arr.length - 1

    while left <= right:
        mid = left + (right - left) / 2

        if arr[mid] == target:
            return mid    // Target found at index mid
        else if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1   // Target not found
```

## 3. Implementation in C

```c
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 4, 7, 10, 12, 15, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
```

## 4. Complexity Analysis
- **Time Complexity**: \(O(\log n)\) — as each step halves the size of the search space.
- **Space Complexity**: \(O(1)\) for iterative binary search (or \(O(\log n)\) for recursive).

## 5. Key Points
- Binary search only works on **sorted** arrays.
- It's efficient for large datasets.
- The divide-and-conquer approach enables it to find elements much faster than linear search in large arrays.

Binary search is a fundamental algorithm and forms the basis for more advanced search techniques.
