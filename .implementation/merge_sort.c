#include <stdio.h>
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

    }
}


void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

   // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }else
        {
            arr[k] = R[j];
            j++;
        }
        k++;

    }

    // Copy the remaining elements of L[], if there are any
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
     // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}
