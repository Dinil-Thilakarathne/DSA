- [1. Quick Sort](#1-quick-sort)
  - [1.1. Key Characteristics of Quick Sort:](#11-key-characteristics-of-quick-sort)
  - [1.2. How Quick Sort Works](#12-how-quick-sort-works)
  - [1.3. Quick Sort Pseudocode](#13-quick-sort-pseudocode)
  - [1.4. Quick Sort Implementation in C](#14-quick-sort-implementation-in-c)
    - [1.4.1. Explanation of the Code](#141-explanation-of-the-code)
  - [1.5. Pros and Cons of Quick Sort](#15-pros-and-cons-of-quick-sort)
  - [1.6. Optimize Quick sort (Advanced)](#16-optimize-quick-sort-advanced)
    - [1.6.1. **Choosing a Better Pivot (Pivot Selection)**](#161-choosing-a-better-pivot-pivot-selection)
    - [1.6.2. **Use Insertion Sort for Small Partitions**](#162-use-insertion-sort-for-small-partitions)
    - [1.6.3. **Tail Recursion Optimization**](#163-tail-recursion-optimization)
    - [1.6.4. **Three-Way Partitioning for Arrays with Many Duplicates**](#164-three-way-partitioning-for-arrays-with-many-duplicates)
    - [1.6.5. **Iterative Quick Sort**](#165-iterative-quick-sort)
    - [1.6.6. Summary of Quick Sort Optimizations](#166-summary-of-quick-sort-optimizations)

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

## 1.6. Optimize Quick sort (Advanced)

Quick Sort is already an efficient sorting algorithm with an average time complexity of \(O(n \log n)\). However, it has a worst-case time complexity of \(O(n^2)\), especially when the pivot selection is poor, such as choosing the first or last element in an already sorted or nearly sorted array. Here are some ways to optimize Quick Sort to improve performance and reduce the likelihood of encountering the worst-case scenario:

### 1.6.1. **Choosing a Better Pivot (Pivot Selection)**
   - **Median-of-Three Pivot:** This is a common optimization where you choose the pivot as the median of three values: the first, middle, and last elements of the array. This generally improves the balance of the partition, especially on nearly sorted or reverse-sorted arrays.
   - **Random Pivot:** Choose a random element as the pivot. This reduces the chance of encountering the worst-case scenario, making it more likely to achieve the average \(O(n \log n)\) performance.

   **Median-of-Three Pivot Example Code:**
   ```c
   int medianOfThree(int arr[], int left, int right) {
       int mid = left + (right - left) / 2;
       if (arr[left] > arr[mid]) {
           int temp = arr[left];
           arr[left] = arr[mid];
           arr[mid] = temp;
       }
       if (arr[left] > arr[right]) {
           int temp = arr[left];
           arr[left] = arr[right];
           arr[right] = temp;
       }
       if (arr[mid] > arr[right]) {
           int temp = arr[mid];
           arr[mid] = arr[right];
           arr[right] = temp;
       }
       return mid;
   }
   ```

### 1.6.2. **Use Insertion Sort for Small Partitions**
   - For small subarrays, Quick Sort’s overhead can be inefficient. When the size of the subarray becomes small (typically 10-20 elements), switch to Insertion Sort.
   - This hybrid approach is faster because Insertion Sort has low overhead and performs well on small arrays.

   **Example Code for Hybrid Quick Sort:**
   ```c
   #define CUTOFF 10 // Threshold to switch to Insertion Sort

   void insertionSort(int arr[], int left, int right) {
       for (int i = left + 1; i <= right; i++) {
           int key = arr[i];
           int j = i - 1;
           while (j >= left && arr[j] > key) {
               arr[j + 1] = arr[j];
               j--;
           }
           arr[j + 1] = key;
       }
   }

   void optimizedQuickSort(int arr[], int left, int right) {
       if (right - left < CUTOFF) { // If the partition is small
           insertionSort(arr, left, right);
           return;
       }

       int pivotIndex = medianOfThree(arr, left, right);
       int pivot = arr[pivotIndex];

       // Swap pivot to end for partitioning
       int temp = arr[pivotIndex];
       arr[pivotIndex] = arr[right];
       arr[right] = temp;

       // Partitioning
       int i = left - 1;
       for (int j = left; j < right; j++) {
           if (arr[j] < pivot) {
               i++;
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
       i++;
       arr[right] = arr[i];
       arr[i] = pivot;

       optimizedQuickSort(arr, left, i - 1);
       optimizedQuickSort(arr, i + 1, right);
   }
   ```

### 1.6.3. **Tail Recursion Optimization**
   - Instead of recursively sorting both halves, sort the smaller half recursively and use a loop to sort the larger half. This reduces the maximum recursion depth and helps save stack space.

   **Example of Tail Recursion Optimization:**
   ```c
   void tailRecursiveQuickSort(int arr[], int left, int right) {
       while (left < right) {
           int pivotIndex = partition(arr, left, right);

           // Recursively sort the smaller partition
           if (pivotIndex - left < right - pivotIndex) {
               tailRecursiveQuickSort(arr, left, pivotIndex - 1);
               left = pivotIndex + 1;
           } else {
               tailRecursiveQuickSort(arr, pivotIndex + 1, right);
               right = pivotIndex - 1;
           }
       }
   }
   ```

### 1.6.4. **Three-Way Partitioning for Arrays with Many Duplicates**
   - When there are many repeated elements, Quick Sort can waste time repeatedly partitioning the same values.
   - **Three-Way Partitioning:** This approach partitions the array into three sections: elements less than the pivot, elements equal to the pivot, and elements greater than the pivot. This makes it more efficient on arrays with many duplicates.

   **Three-Way Partition Example Code:**
   ```c
   void threeWayPartition(int arr[], int left, int right) {
       if (right <= left) return;

       int lt = left, gt = right;
       int pivot = arr[left];
       int i = left;

       while (i <= gt) {
           if (arr[i] < pivot) {
               int temp = arr[lt];
               arr[lt] = arr[i];
               arr[i] = temp;
               lt++;
               i++;
           } else if (arr[i] > pivot) {
               int temp = arr[i];
               arr[i] = arr[gt];
               arr[gt] = temp;
               gt--;
           } else {
               i++;
           }
       }
       threeWayPartition(arr, left, lt - 1);
       threeWayPartition(arr, gt + 1, right);
   }
   ```

### 1.6.5. **Iterative Quick Sort**
   - Instead of recursion, you can use an explicit stack to keep track of the subarrays that need to be sorted. This avoids the risk of stack overflow from deep recursion.
   - This is especially useful in environments where stack memory is limited or where you want more control over memory usage.

   **Iterative Quick Sort Code Outline:**
   ```c
   void iterativeQuickSort(int arr[], int n) {
       int stack[n];
       int top = -1;

       stack[++top] = 0;
       stack[++top] = n - 1;

       while (top >= 0) {
           int right = stack[top--];
           int left = stack[top--];

           int pivotIndex = partition(arr, left, right);

           if (pivotIndex - 1 > left) {
               stack[++top] = left;
               stack[++top] = pivotIndex - 1;
           }
           if (pivotIndex + 1 < right) {
               stack[++top] = pivotIndex + 1;
               stack[++top] = right;
           }
       }
   }
   ```

### 1.6.6. Summary of Quick Sort Optimizations
- **Better Pivot Selection:** Use median-of-three or random pivot selection to avoid worst-case scenarios.
- **Switch to Insertion Sort for Small Subarrays:** Use a hybrid approach to handle small arrays more efficiently.
- **Tail Recursion Optimization:** Sort smaller parts first and loop to reduce recursion depth.
- **Three-Way Partitioning:** Efficient for arrays with many duplicate elements.
- **Iterative Quick Sort:** Avoid recursion by using an explicit stack for partitioning.

These optimizations make Quick Sort more efficient and versatile, especially for large datasets.
