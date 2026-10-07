#include <stdio.h>
#include <windows.h>

// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Bubble sort algorithm
void BubbleSort(int arr[], int length){
    int isSorted = 0;       // Tracks if array is already sorted or not.
    for (int i = 0; i < length; i++)    {
        isSorted = 1;
        for (int j = 0; j < length - i; j++){
            if (arr[j] > arr[j + 1]){

                // Swap the elements if they are out of their correct order.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted) break;
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    BubbleSort(arr, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}