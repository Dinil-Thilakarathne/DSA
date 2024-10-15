#include <stdio.h>
#include "utils.h"

void selection_sort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for(int j = minIndex + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}
