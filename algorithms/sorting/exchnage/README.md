- [1. How Exchange Sort Works](#1-how-exchange-sort-works)
- [2. Pseudocode for Exchange Sort](#2-pseudocode-for-exchange-sort)
  - [2.1. Example](#21-example)
- [3. Exchange Sort vs. Bubble Sort](#3-exchange-sort-vs-bubble-sort)
- [4. Code Example in C](#4-code-example-in-c)
- [5. Time Complexity](#5-time-complexity)

Exchange Sort is a simple comparison-based sorting algorithm that works by repeatedly comparing and swapping adjacent elements that are out of order. The idea is to go through the list, find pairs of elements that are not in the correct order, and swap them until the entire list is sorted. This technique is often applied in sorting algorithms like Bubble Sort, which is a specific type of exchange sort.

## 1. How Exchange Sort Works
1. Start with the first element of the list.
2. Compare the current element with each subsequent element.
3. If the current element is greater than the element being compared, swap them.
4. Move to the next element and repeat the process until the list is sorted.

The algorithm continues this process until no more swaps are needed, meaning that the list is sorted.

## 2. Pseudocode for Exchange Sort
Here's a simple pseudocode to illustrate the basic idea:

```plaintext
for i from 0 to n - 1
    for j from i + 1 to n - 1
        if array[i] > array[j]
            swap array[i] and array[j]
```

### 2.1. Example
Suppose we have an array `[5, 3, 8, 4, 2]`:
1. Start with the first element `5` and compare it to each other element.
2. Swap `5` with `3` (because `5 > 3`), resulting in `[3, 5, 8, 4, 2]`.
3. Continue comparing `5` with `8`, `4`, and `2`, and swap where necessary.
4. Move to the next element and repeat the process until the array is sorted: `[2, 3, 4, 5, 8]`.

## 3. Exchange Sort vs. Bubble Sort
While both are based on swapping elements, the difference is that Bubble Sort swaps adjacent elements during each pass, while Exchange Sort compares an element with all other elements after it and swaps as needed. As a result, Bubble Sort generally involves more passes through the list.

## 4. Code Example in C
Here’s an example of how to implement Exchange Sort in C:

```c
#include <stdio.h>

void exchange_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    displayArray(arr, n);

    exchange_sort(arr, n);

    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}
```

## 5. Time Complexity
- **Best Case:** \(O(n^2)\)
- **Average Case:** \(O(n^2)\)
- **Worst Case:** \(O(n^2)\)

Exchange Sort is inefficient for large lists due to its \(O(n^2)\) time complexity, similar to other simple sorting algorithms like Bubble Sort and Selection Sort. However, it can be useful for small lists or for educational purposes.
