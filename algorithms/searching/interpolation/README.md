- [1. How Interpolation Search Works:](#1-how-interpolation-search-works)
- [2. Pseudocode](#2-pseudocode)
- [3. Implementation in C](#3-implementation-in-c)
- [4. Complexity Analysis](#4-complexity-analysis)
- [5. Key Points](#5-key-points)

 Interpolation search is an improved version of binary search that is more efficient for uniformly distributed sorted arrays. It works by estimating the position of the target value based on the value of the elements in the array rather than always splitting the array in half. This method can significantly reduce the number of comparisons in certain scenarios.

## 1. How Interpolation Search Works:
1. **Calculate the Position**: Given a target value, the algorithm estimates the position in the array where the target might be located using a formula based on the values of the first and last elements of the array.
2. **Check the Estimated Position**: If the target value is found at the estimated position, the search is complete.
3. **Narrow Down the Search**: If the target value is less than the element at the estimated position, the search continues in the lower part of the array. If it is greater, the search continues in the upper part.
4. **Repeat**: This process is repeated until the target is found or the sub-array becomes empty.

## 2. Pseudocode
Here’s a simple pseudocode for interpolation search:

```plaintext
function interpolationSearch(arr, size, target):
    low = 0
    high = size - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1

        // Estimate position
        pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]))

        if arr[pos] == target:
            return pos
        else if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1  // Target not found
```

## 3. Implementation in C

```c
#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low;  // Return the index if found
            }
            return -1;  // Target not found
        }

        // Estimate position
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == target) {
            return pos;  // Return the index if found
        } else if (arr[pos] < target) {
            low = pos + 1;  // Search in the right half
        } else {
            high = pos - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    int result = interpolationSearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
```

## 4. Complexity Analysis
- **Time Complexity**:
  - Best case: \(O(1)\) — when the target is at the first position.
  - Average case: \(O(\log \log n)\) — for uniformly distributed data.
  - Worst case: \(O(n)\) — if the data is not uniformly distributed.

- **Space Complexity**: \(O(1)\) — constant space, as it does not require additional storage beyond a few variables.

## 5. Key Points
- Interpolation search is **more efficient** than binary search when the data is uniformly distributed.
- It requires the input array to be **sorted**.
- The effectiveness of interpolation search decreases with non-uniform distributions.

Interpolation search is particularly useful for applications where the data is predictable, such as in databases or statistical applications, and can be much faster than simpler search methods like linear search and even binary search in those cases.
