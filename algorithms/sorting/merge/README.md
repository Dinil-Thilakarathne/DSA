- [1. Merge Sort](#1-merge-sort)
  - [1.1. Pseudocode for Merge Sort](#11-pseudocode-for-merge-sort)
  - [1.2. C Code for Merge Sort](#12-c-code-for-merge-sort)
  - [1.3. Explanation of Merge Sort](#13-explanation-of-merge-sort)
  - [1.4. Characteristics of Merge Sort](#14-characteristics-of-merge-sort)

# 1. Merge Sort

**Merge Sort** is a divide-and-conquer sorting algorithm that divides the input array into two halves, recursively sorts each half, and then merges the sorted halves back together. It has a time complexity of \(O(n \log n)\) in the worst, average, and best cases.

## 1.1. Pseudocode for Merge Sort
```
procedure MergeSort(array A, int left, int right)
    if left < right then
        mid = (left + right) / 2
        MergeSort(A, left, mid)
        MergeSort(A, mid + 1, right)
        Merge(A, left, mid, right)

procedure Merge(array A, int left, int mid, int right)
    // Create temporary arrays
    n1 = mid - left + 1
    n2 = right - mid
    create array L[n1], R[n2]

    // Copy data to temporary arrays L[] and R[]
    for i from 0 to n1 - 1 do
        L[i] = A[left + i]
    for j from 0 to n2 - 1 do
        R[j] = A[mid + 1 + j]

    // Merge the temporary arrays back into A[left..right]
    i = 0 // Initial index of first sub-array
    j = 0 // Initial index of second sub-array
    k = left // Initial index of merged sub-array

    while i < n1 and j < n2 do
        if L[i] <= R[j] then
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
        k = k + 1

    // Copy the remaining elements of L[], if there are any
    while i < n1 do
        A[k] = L[i]
        i = i + 1
        k = k + 1

    // Copy the remaining elements of R[], if there are any
    while j < n2 do
        A[k] = R[j]
        j = j + 1
        k = k + 1
end procedure
```

## 1.2. C Code for Merge Sort
```c
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```

## 1.3. Explanation of Merge Sort
1. **Divide**: The array is divided into two halves until each sub-array contains a single element.
2. **Conquer**: Each sub-array is sorted recursively.
3. **Combine**: The sorted sub-arrays are merged back together to form the sorted array.

## 1.4. Characteristics of Merge Sort
- **Stable**: Merge sort maintains the relative order of records with equal keys.
- **Not In-Place**: It requires additional space proportional to the array size for temporary arrays.
- **Time Complexity**: \(O(n \log n)\) for all cases (worst, average, best).
- **Space Complexity**: \(O(n)\) due to the auxiliary space required for merging.

Merge Sort is particularly efficient for large datasets and is often used in practice when stability is a concern.
