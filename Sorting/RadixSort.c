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


// Fucntion to sort based on radix
void CountSort(int arr[], int length, int exp){

    int *countArray = (int*)calloc(sizeof(int), 10);
    int *originalArray = (int *)malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++){
        int digit = (arr[i]/exp)%10;
        countArray[digit]++;
    }

    // Prefix Sum array
    for(int j = 1; j < 10; j++){
        countArray[j] = countArray[j - 1] + countArray[j];
    }

    for(int k = length - 1; k >=0; k--){
        int digit = (arr[k]/exp)%10;
        originalArray[countArray[digit] - 1] = arr[k];
        countArray[digit]--;
    }

    // Copy back all elements into original array.
    for(int l = 0; l < length; l++){
        arr[l] = originalArray[l];
    }

    // Free the memory location for helper arrays.
    free(countArray);
    free(originalArray);
}

// Radix Sort algorithm
void RadixSort(int arr[], int length){
    int max = maximum(arr, length);
    for(int exp = 1; max/exp > 0; exp = exp*10){
        CountSort(arr, length, exp);
    }
}

int main()
{
    int arr[] = {1, 5, 7, 3, 9, 5, 4, 8, 0, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    Traverse(arr, length);
    RadixSort(arr, length);
    printf("\n");
    printf("Sorted Array: ");
    Traverse(arr, length);
    return 0;
}