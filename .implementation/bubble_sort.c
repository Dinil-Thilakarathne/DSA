#include <stdio.h>
#include "utils.h"

/**
 * @brief Sorts an integer array in ascending order using the bubble sort algorithm.
 *
 * This function implements the bubble sort algorithm to sort an array of integers.
 * It repeatedly steps through the list, compares adjacent elements and swaps them
 * if they are in the wrong order. The pass through the list is repeated until the
 * array is sorted.
 *
 * @param array The integer array to be sorted.
 * @param size The number of elements in the array.
 */

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
