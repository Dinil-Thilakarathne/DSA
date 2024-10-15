#include <stdio.h>
#include "utils.h"
#include "sort_algorithms.h"

int main(){
    int size = 100;
    int array[size];

    populateArray(array, size, 0 , 200);
    displayArray(array, size);

    // bubble_sort(array, size);
    // optimal_bubble_sort(array, size);

    // merge_sort(array, 0, size-1);

    // insertion_sort(array,size);

    // selection_sort(array,size);

    // quickSort(array,0,size);
    // optimal_quickSort(array,0,size);

    exchnage_sort(array,size);

    displayArray(array, size);

}
