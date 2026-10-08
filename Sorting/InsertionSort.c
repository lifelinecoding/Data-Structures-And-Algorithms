#include <stdio.h>
#include <windows.h>

// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Insertion sort algorithm
void InsertionSort(int arr[], int length){
    int temp, j;

    for(int i = 1; i < length; i++){
        temp = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    InsertionSort(arr, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}