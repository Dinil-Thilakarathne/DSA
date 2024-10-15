#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void populateArray(int *array, int size, int min, int max) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % (max - min + 1) + min;
    }
}


void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }

    puts("");
}


void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;

}
