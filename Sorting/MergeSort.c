#include <stdio.h>
#include <windows.h>
#include<stdlib.h>


// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Function to merge two sorted arrays
void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;

    int *new_arr = (int*)malloc(sizeof(int)*(high - low + 1));

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
        new_arr[k++] = arr[i++];
        }
        else {
        new_arr[k++] = arr[j++];
        }
    }

    // Copy the remaining elements
    while(i <= mid){
        new_arr[k++] = arr[i++];
    }

    while(j <= high){
        new_arr[k++] = arr[j++];
    }

    // Restore the elements back into original array
    for(int i = 0; i < k; i++){
        arr[low + i] = new_arr[i];
    }

    free(new_arr);
}


// Merge Sort sort algorithm
void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    MergeSort(arr, 0, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}