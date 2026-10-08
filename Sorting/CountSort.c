#include <stdio.h>
#include <windows.h>
#include<stdlib.h>

// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Function to find maximum number from an array
int maximum(int arr[], int length){
    int max = arr[0];
    for(int i = 1; i < length; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

// Count sort algorithm
void CountSort(int arr[], int length){
    // Find the maximum element.
    int max = maximum(arr, length);

    // Allocate memory for counting array
    int *countArray = (int*)calloc(sizeof(int), max + 1);

    for(int i = 0; i < length; i++){
        countArray[arr[i]] = countArray[arr[i]] + 1;
    }

    int track = 0;
    for(int j = 0; j <= max; j++){
        while(countArray[j] != 0){
            countArray[j] = countArray[j] - 1;
            arr[track++] = j;
        }
    }

    // Free the space of count array.
    free(countArray);
}

int main(){
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    CountSort(arr, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}