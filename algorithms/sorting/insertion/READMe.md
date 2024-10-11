- [1. Insertion Sort](#1-insertion-sort)
  - [1.1. Key Characteristics of Insertion Sort:](#11-key-characteristics-of-insertion-sort)
  - [1.2. How Insertion Sort Works](#12-how-insertion-sort-works)
  - [1.3. Insertion Sort Pseudocode](#13-insertion-sort-pseudocode)
  - [1.4. Insertion Sort Implementation in C](#14-insertion-sort-implementation-in-c)
    - [1.4.1. Explanation of the Code](#141-explanation-of-the-code)
  - [1.5. Example Walkthrough](#15-example-walkthrough)
  - [1.6. Pros and Cons of Insertion Sort](#16-pros-and-cons-of-insertion-sort)
  - [1.7. When to Use Insertion Sort](#17-when-to-use-insertion-sort)

# 1. Insertion Sort

**Insertion Sort** is a simple sorting algorithm that builds the final sorted array one element at a time. It is much like the way we sort playing cards by picking up one card at a time and inserting it into the correct position in our hand. It is particularly useful for small data sets and partially sorted arrays.

## 1.1. Key Characteristics of Insertion Sort:
- **Time Complexity**:
  - Average and Worst case: \(O(n^2)\)
  - Best case: \(O(n)\) (when the array is already sorted)
- **Space Complexity**: \(O(1)\) since it’s an in-place sorting algorithm
- **Stability**: Insertion Sort is **stable** as it preserves the relative order of equal elements.
- **In-Place**: Yes, it doesn’t require extra memory for sorting.

## 1.2. How Insertion Sort Works

Insertion Sort works by dividing the array into a sorted and an unsorted part. Initially, the sorted part contains only the first element, and the rest of the array is unsorted. Then, for each element in the unsorted part, the algorithm:
1. **Picks the next element** and **compares** it to the elements in the sorted part.
2. **Shifts** all elements in the sorted part that are larger than the current element to the right.
3. **Inserts** the current element into its correct position in the sorted part.

This process is repeated until the entire array is sorted.

## 1.3. Insertion Sort Pseudocode

Here is the high-level pseudocode for Insertion Sort:

```
for i = 1 to n-1
    key = array[i]
    j = i - 1

    // Move elements of array[0..i-1], that are greater than key, to one position ahead
    // of their current position
    while j >= 0 and array[j] > key
        array[j + 1] = array[j]
        j = j - 1
    array[j + 1] = key
```

## 1.4. Insertion Sort Implementation in C

Below is the C implementation of the Insertion Sort algorithm:

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
```

### 1.4.1. Explanation of the Code

1. **Outer Loop**: Starts from the second element (index 1) and iterates through each element of the array. This element is the "key" that we need to place in the correct position in the sorted part of the array.

2. **Inner While Loop**: Shifts all elements greater than the key to the right. It continues shifting until it finds the correct position for the key, or until it reaches the beginning of the array.

3. **Insert Key**: After shifting, the key is inserted at its correct position in the sorted part of the array.

4. **Print Array Function**: This helper function prints the elements of the array.

## 1.5. Example Walkthrough

Consider the array `[12, 11, 13, 5, 6]`:

1. **First Iteration**: Key = `11`, Array = `[12, 11, 13, 5, 6]`
   - 12 is shifted to the right.
   - Array becomes `[11, 12, 13, 5, 6]`.

2. **Second Iteration**: Key = `13`, Array = `[11, 12, 13, 5, 6]`
   - 13 is already in the correct position.
   - Array remains `[11, 12, 13, 5, 6]`.

3. **Third Iteration**: Key = `5`, Array = `[11, 12, 13, 5, 6]`
   - 13, 12, and 11 are shifted to the right.
   - Array becomes `[5, 11, 12, 13, 6]`.

4. **Fourth Iteration**: Key = `6`, Array = `[5, 11, 12, 13, 6]`
   - 13, 12, and 11 are shifted to the right.
   - Array becomes `[5, 6, 11, 12, 13]`.

## 1.6. Pros and Cons of Insertion Sort

#### Pros:
- **Simple to Implement** and understand.
- **Efficient for Small Data Sets** and mostly sorted arrays.
- **In-Place and Stable** sorting.

#### Cons:
- **Inefficient for Large Data Sets** due to its \(O(n^2)\) complexity in the average and worst cases.

## 1.7. When to Use Insertion Sort

Insertion Sort is best suited for:
- **Small Arrays**: Its simplicity and low overhead make it faster than more complex algorithms for small input sizes.
- **Nearly Sorted Arrays**: Since its best case is \(O(n)\), it’s efficient for arrays that are already almost sorted.

While not the fastest sorting algorithm for large arrays, Insertion Sort has an advantage in simplicity and its stability makes it useful in cases where the relative ordering of equal elements is important.
