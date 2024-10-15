#include <stdio.h>
#include "utils.h"

void exchnage_sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }

        }
    }
}

void optimized_exchange_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;  // Early termination flag
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
        // If no two elements were swapped in the inner loop, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}
