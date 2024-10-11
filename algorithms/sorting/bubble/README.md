- [1. Bubble Sort](#1-bubble-sort)
  - [1.1. How It Works:](#11-how-it-works)
  - [1.2. Time Complexity:](#12-time-complexity)
  - [1.3. Space Complexity:](#13-space-complexity)
  - [1.4. Pros and Cons:](#14-pros-and-cons)
  - [1.5. Implementation](#15-implementation)
    - [1.5.1. Pseudocode for Normal Bubble Sort:](#151-pseudocode-for-normal-bubble-sort)
    - [1.5.2. C Code for Normal Bubble Sort:](#152-c-code-for-normal-bubble-sort)
  - [1.6. Optimal Bubble Sort](#16-optimal-bubble-sort)
    - [1.6.1. **Pseudocode for Optimal Bubble Sort:**](#161-pseudocode-for-optimal-bubble-sort)
    - [1.6.2. C Code for Optimal Bubble Sort:](#162-c-code-for-optimal-bubble-sort)
  - [1.7. Real-word example](#17-real-word-example)

# 1. Bubble Sort

Bubble Sort is one of the simplest sorting algorithms. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

## 1.1. How It Works:

- Compare each pair of adjacent elements.
- Swap them if the first element is greater than the second.
- Repeat this process for all elements, and repeat for all subsequent elements until no swaps are needed.

## 1.2. Time Complexity:

- **Worst-case**: `O(n^2)`
- **Best-case**: `O(n)` (if the array is already sorted)
- **Average-case**: `O(n^2)`

## 1.3. Space Complexity:

- **O(1)** because it is an in-place sorting algorithm. Stable.

## 1.4. Pros and Cons:

- **Pros**: Easy to implement and understand.
- **Cons**: Inefficient for large datasets.

## 1.5. Implementation

### 1.5.1. Pseudocode for Normal Bubble Sort:
```plaintext
procedure BubbleSort(array A)
    n = length(A)
    for i from 0 to n - 1 do
        for j from 0 to n - i - 2 do
            if A[j] > A[j + 1] then
                swap A[j] and A[j + 1]
end procedure

```
### 1.5.2. C Code for Normal Bubble Sort:
```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

## 1.6. Optimal Bubble Sort

The optimal version of Bubble Sort introduces a flag to check if any swaps occurred during a pass. If no swaps occur, the array is already sorted, and we can terminate early.

### 1.6.1. **Pseudocode for Optimal Bubble Sort:**
```
procedure OptimalBubbleSort(array A)
    n = length(A)
    for i from 0 to n - 1 do
        swapped = false
        for j from 0 to n - i - 2 do
            if A[j] > A[j + 1] then
                swap A[j] and A[j + 1]
                swapped = true
        if not swapped then
            break
end procedure
```
### 1.6.2. C Code for Optimal Bubble Sort:
```c
#include <stdio.h>
#include <stdbool.h>

void optimalBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is sorted
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    optimalBubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```
#### Summary

- **Normal Bubble Sort**: Continuously compares adjacent elements and swaps them if they are in the wrong order, performing `n-1` passes through the array.
- **Optimal Bubble Sort**: Introduces a flag to stop the algorithm early if the array becomes sorted before completing all passes. This makes it more efficient for partially sorted arrays.

## 1.7. Real-word example
```c
// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

```
