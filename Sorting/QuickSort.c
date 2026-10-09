#include <stdio.h>
#include <windows.h>
#include<stdlib.h>


// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Helper function to swap elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to merge two sorted arrays
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(1){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i > j) break;
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[j], &arr[low]);
    return j;
}


// Quick Sort sort algorithm
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    QuickSort(arr, 0, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}