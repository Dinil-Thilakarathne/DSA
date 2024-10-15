#include <stdio.h>
#include "utils.h"


// normal bubble sort
void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }

}



void optimal_bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }
    // If no two elements were swapped by inner loop, then the array is sorted
    if (swapped == 0)
        break;
    }
}
