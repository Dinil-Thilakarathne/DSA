- [1. Quick Sort](#1-quick-sort)
  - [1.1. Key Characteristics of Quick Sort:](#11-key-characteristics-of-quick-sort)
  - [1.2. How Quick Sort Works](#12-how-quick-sort-works)
  - [1.3. Quick Sort Pseudocode](#13-quick-sort-pseudocode)
  - [1.4. Quick Sort Implementation in C](#14-quick-sort-implementation-in-c)
    - [1.4.1. Explanation of the Code](#141-explanation-of-the-code)
  - [1.5. Pros and Cons of Quick Sort](#15-pros-and-cons-of-quick-sort)

# 1. Quick Sort

**Quick Sort** is a highly efficient sorting algorithm that uses a divide-and-conquer approach. It works by selecting a *pivot* element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This process results in a sorted array.

## 1.1. Key Characteristics of Quick Sort:
- **Time Complexity**:
  - Average case: \(O(n \log n)\)
  - Worst case: \(O(n^2)\) (occurs when the pivot is the smallest or largest element each time)
  - Best case: \(O(n \log n)\)
- **Space Complexity**: \(O(\log n)\) due to recursion stack
- **Stability**: Quick Sort is **not stable** by default, meaning that it may not preserve the order of equal elements.
- **In-Place**: Yes, it doesn’t require additional storage for sorting (apart from the recursion stack).

## 1.2. How Quick Sort Works

1. **Choose a Pivot**: Select an element from the array as the pivot. There are several strategies for choosing a pivot:
   - First element
   - Last element
   - Random element
   - Median element (median of three method)

2. **Partitioning**: Rearrange the elements in the array such that all elements less than the pivot are on the left side, and all elements greater than the pivot are on the right side. After partitioning, the pivot is in its final sorted position.

3. **Recursively Sort the Sub-Arrays**: Recursively apply the same procedure to the sub-arrays of elements with smaller and greater values.

4. **Combine**: Since the elements around the pivot are already sorted relative to each other, there’s no need for additional work to combine the arrays.

## 1.3. Quick Sort Pseudocode

Here is a high-level pseudocode for Quick Sort:

```
function quickSort(array, low, high)
    if low < high
        // Partition the array and get the pivot index
        pivotIndex = partition(array, low, high)

        // Recursively sort elements before and after the partition
        quickSort(array, low, pivotIndex - 1)
        quickSort(array, pivotIndex + 1, high)
```

#### Partition Function

The `partition` function is a crucial part of Quick Sort. It moves elements around the pivot and returns the pivot's final index.

```
function partition(array, low, high)
    // Choose the last element as pivot
    pivot = array[high]
    i = low - 1 // i is the index of the smaller element

    for j = low to high - 1
        if array[j] <= pivot
            i = i + 1
            swap array[i] with array[j]

    swap array[i + 1] with array[high] // Place the pivot element in its correct position
    return (i + 1)
```

## 1.4. Quick Sort Implementation in C

Here’s how you can implement Quick Sort in C:

```c
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

### 1.4.1. Explanation of the Code

1. **Partition Function**: This function selects the last element as the pivot. It then iterates through the array and rearranges elements around the pivot. Elements smaller than the pivot are moved to its left, and elements greater than the pivot are moved to its right.

2. **QuickSort Function**: This function is called recursively. It partitions the array around a pivot and then sorts the left and right sub-arrays independently.

3. **Print Array Function**: A helper function to print the elements of the array after sorting.

## 1.5. Pros and Cons of Quick Sort

#### Pros:
- **Fast** on average and typically performs well in practice.
- **In-place**: It doesn’t need additional space, unlike Merge Sort.
- **Cache-friendly** due to sequential memory access.

#### Cons:
- **Not stable**: Equal elements may change their relative order.
- **Worst-case performance** is \(O(n^2)\), although this is rare with a good pivot selection strategy.

Quick Sort is one of the most commonly used sorting algorithms due to its efficiency and in-place nature. However, it’s essential to be aware of its limitations and consider the use of other algorithms, such as Merge Sort, when stability is required or when the data set is known to be nearly sorted (where Quick Sort may perform poorly).
