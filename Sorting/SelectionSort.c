#include <stdio.h>
#include <windows.h>

// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Selection sort algorithm
void SelectionSort(int arr[], int length){
    int minValue, minIndex, temp;

    for(int i = 0; i < length; i++){
        minIndex = i;
        minValue = arr[i];

        for(int j = i + 1; j < length; j++){
            if(arr[j] < minValue){
                minValue = arr[j];
                minIndex = j;
            }
        }

        if(minIndex != i){
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    SelectionSort(arr, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}