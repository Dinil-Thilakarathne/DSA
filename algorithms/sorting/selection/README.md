- [1. Selection Sort](#1-selection-sort)
  - [1.1. Key Characteristics of Selection Sort:](#11-key-characteristics-of-selection-sort)
  - [1.2. How Selection Sort Works](#12-how-selection-sort-works)
  - [1.3. Selection Sort Pseudocode](#13-selection-sort-pseudocode)
  - [1.4. Selection Sort Implementation in C](#14-selection-sort-implementation-in-c)
    - [1.4.1. Explanation of the Code](#141-explanation-of-the-code)
  - [1.5. Example Walkthrough](#15-example-walkthrough)
  - [1.6. Pros and Cons of Selection Sort](#16-pros-and-cons-of-selection-sort)
  - [1.7. When to Use Selection Sort](#17-when-to-use-selection-sort)
  - [1.8. Optimal selection sort](#18-optimal-selection-sort)
    - [1.8.1. Optimizations for Selection Sort](#181-optimizations-for-selection-sort)
    - [1.8.2. Min-Max Selection Sort in C](#182-min-max-selection-sort-in-c)
    - [1.8.3. Explanation of Min-Max Selection Sort Code](#183-explanation-of-min-max-selection-sort-code)
    - [1.8.4. Summary](#184-summary)

# 1. Selection Sort

**Selection Sort** is a simple comparison-based sorting algorithm. It works by repeatedly finding the minimum (or maximum, depending on sorting order) element from the unsorted portion of the array and swapping it with the first unsorted element, thus expanding the sorted portion of the array one element at a time.

## 1.1. Key Characteristics of Selection Sort:
- **Time Complexity**:
  - Best, Average, and Worst case: \(O(n^2)\) because it involves nested loops, one for each element and another for finding the minimum/maximum element.
- **Space Complexity**: \(O(1)\) as it sorts the array in-place.
- **Stability**: Selection Sort is **not stable** by default, as it may change the relative order of equal elements.
- **In-Place**: Yes, Selection Sort doesn’t require extra memory for sorting.

## 1.2. How Selection Sort Works

Selection Sort works by:
1. Dividing the array into a sorted and an unsorted portion.
2. Iterating over the unsorted portion to find the minimum (or maximum) element.
3. Swapping that minimum element with the first unsorted element, effectively growing the sorted portion by one.
4. Repeating this process until the entire array is sorted.

## 1.3. Selection Sort Pseudocode

Here's the high-level pseudocode for Selection Sort:

```
for i = 0 to n - 1
    minIndex = i
    for j = i + 1 to n
        if array[j] < array[minIndex]
            minIndex = j
    swap array[i] with array[minIndex]
```

## 1.4. Selection Sort Implementation in C

Here is a C implementation of Selection Sort:

```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
```

### 1.4.1. Explanation of the Code

1. **Outer Loop**: Iterates over the array, one element at a time, expanding the sorted portion of the array.
2. **Inner Loop**: Finds the index of the minimum element in the unsorted portion of the array.
3. **Swapping Elements**: Once the minimum element is found, it is swapped with the first unsorted element, so the sorted portion of the array grows.
4. **Print Array Function**: This function is used to print the sorted array.

## 1.5. Example Walkthrough

Let's take an example array `[64, 25, 12, 22, 11]` to illustrate how Selection Sort works:

1. **First Pass**:
   - `i = 0`, the initial minimum index is `0` (value `64`).
   - Find the minimum in the range `[25, 12, 22, 11]` (values from index `1` to `4`).
   - `11` (index `4`) is the smallest element.
   - Swap `64` and `11`.
   - Array becomes: `[11, 25, 12, 22, 64]`.

2. **Second Pass**:
   - `i = 1`, initial minimum index is `1` (value `25`).
   - Find the minimum in the range `[12, 22, 64]` (values from index `2` to `4`).
   - `12` (index `2`) is the smallest element.
   - Swap `25` and `12`.
   - Array becomes: `[11, 12, 25, 22, 64]`.

3. **Third Pass**:
   - `i = 2`, initial minimum index is `2` (value `25`).
   - Find the minimum in the range `[22, 64]` (values from index `3` to `4`).
   - `22` (index `3`) is the smallest element.
   - Swap `25` and `22`.
   - Array becomes: `[11, 12, 22, 25, 64]`.

4. **Fourth Pass**:
   - `i = 3`, initial minimum index is `3` (value `25`).
   - Find the minimum in the range `[64]` (only index `4` remains).
   - Array remains `[11, 12, 22, 25, 64]`, as it is now sorted.

## 1.6. Pros and Cons of Selection Sort

#### Pros:
- **Simple to Understand and Implement**.
- **In-Place Sorting Algorithm**, requiring no extra space.
- **Good for Small Data Sets** or arrays where memory is limited.

#### Cons:
- **Inefficient for Large Data Sets** due to \(O(n^2)\) time complexity.
- **Not Stable** by default, as it may change the relative order of equal elements.

## 1.7. When to Use Selection Sort

Selection Sort is best used when:
- The **list size is small**, as its time complexity makes it inefficient for large lists.
- **Memory usage is a concern**, as it sorts in-place without needing additional memory.
- **Swapping operations** need to be minimized, as Selection Sort performs fewer swaps than algorithms like Bubble Sort.

## 1.8. Optimal selection sort
The standard Selection Sort algorithm has a time complexity of \(O(n^2)\), so it's inherently not optimal for large datasets. However, there are a few ways to improve it slightly. While it won't reach the efficiency of more advanced algorithms like Quick Sort or Merge Sort, you can reduce the number of swaps and make some optimizations to minimize unnecessary operations.

### 1.8.1. Optimizations for Selection Sort

#### 1. **Min-Max Selection Sort**
   - Instead of finding just the minimum element in each pass, you can find both the minimum and maximum elements in each pass and place them at the beginning and end of the unsorted portion, respectively.
   - This way, you reduce the number of iterations by half because both ends of the array are sorted simultaneously.

   **How It Works:**
   - In each pass, locate the smallest and largest elements in the remaining unsorted portion.
   - Swap the smallest element to the beginning and the largest element to the end of the unsorted portion.

   **Pseudocode:**
   ```text
   for i = 0 to n / 2 - 1
       minIndex = i
       maxIndex = i
       for j = i + 1 to n - i - 1
           if array[j] < array[minIndex]
               minIndex = j
           if array[j] > array[maxIndex]
               maxIndex = j
       swap array[i] with array[minIndex]

       // If maxIndex is the position of minIndex after the swap, update it
       if maxIndex == i
           maxIndex = minIndex

       swap array[n - i - 1] with array[maxIndex]
   ```

   This approach reduces the number of passes by half, which helps improve performance a bit.

#### 2. **Optimizing for Nearly Sorted Arrays**
   - If the array is nearly sorted, Selection Sort can be modified to stop early if no swaps are needed.
   - In each pass, after finding the minimum element, check if the position is already correct. If the array becomes sorted before the algorithm completes, you can stop early.
   - However, this doesn’t help much for fully random data, so it’s only useful for specific cases like partially sorted arrays.

#### 3. **Reducing the Number of Swaps**
   - Standard Selection Sort performs a swap each time it finds the minimum element in the unsorted portion.
   - Instead, you could store the position of the minimum element and only perform the swap at the end of each pass. This reduces the number of swaps significantly but doesn’t change the algorithm’s overall time complexity.
   - You could further improve the swap operation by using a function that avoids swapping if the minimum element is already in the correct position.

#### 4. **Using Binary Search for Minimum Element (Advanced)**
   - In the inner loop, use binary search instead of a linear search to find the minimum element’s position. This doesn’t change the overall time complexity but can sometimes help reduce the time spent in each iteration if the data is sorted or nearly sorted.
   - Note that this optimization is not commonly used due to the overhead of binary search in every iteration.

### 1.8.2. Min-Max Selection Sort in C

Here's a simple C implementation of the Min-Max Selection Sort:

```c
#include <stdio.h>

void minMaxSelectionSort(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int minIndex = i;
        int maxIndex = i;

        // Find the minimum and maximum elements in the unsorted portion
        for (int j = i + 1; j < n - i; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Swap the minimum element to the beginning
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Update the maxIndex if it was at the initial minIndex
        if (maxIndex == i) {
            maxIndex = minIndex;
        }

        // Swap the maximum element to the end
        temp = arr[n - i - 1];
        arr[n - i - 1] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    minMaxSelectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
```

### 1.8.3. Explanation of Min-Max Selection Sort Code
- In each pass, the algorithm finds the minimum and maximum elements in the unsorted portion.
- The minimum element is swapped to the beginning of the unsorted portion, and the maximum element is swapped to the end of the unsorted portion.
- This reduces the number of passes, effectively halving the number of iterations needed.

### 1.8.4. Summary
These optimizations will make Selection Sort a bit more efficient, but it will still remain \(O(n^2)\). For small arrays or specific types of data (like nearly sorted arrays), these optimizations can improve performance. For larger arrays, however, consider using more efficient sorting algorithms like Merge Sort or Quick Sort.
