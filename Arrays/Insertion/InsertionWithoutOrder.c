#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Insertion at the last.
void InsertAtEnd(int arr[], int *size, int capacity, int newItem)
{
    if (*size >= capacity)
    {
        printf("Array is full.\n");
    }
    else
    {
        arr[*size] = newItem;
        *size = *size + 1;
    }
}

// Insertion at the starting.
void InsertAtStart(int arr[], int *size, int capacity, int newItem){
    if(*size >= capacity){
        printf("Array is full.\n");
    }
    else{
        int temp = arr[0];
        arr[0] = newItem;
        arr[*size] = temp;

        *size = *size + 1;
    }
}

// Insertion at the particular index.
void InsertAtParticularIndex(int arr[], int *size, int capacity, int index, int newItem){
    if(*size >= capacity){
        printf("Array is full.\n");
    }    
    else if(index > *size){
        printf("Invalid index.\n");
    }
    else {
        int temp = arr[index];
        arr[index] = newItem;
        arr[*size] = temp;
        *size = *size + 1;
    }
}


// Function to display array elements
void Display(int arr[], int *size)
{
    for (int index = 0; index < *size; index++)
    {
        printf("%d ", arr[index]);
    }
}

int main()
{
    // Allocating memory for array with 10 integers.
    int *arr = (int *)malloc(sizeof(int) * 10);
    int capacity = 10;
    int size = 0;

    InsertAtEnd(arr, &size, capacity, 10);
    InsertAtEnd(arr, &size, capacity, 5);
    InsertAtEnd(arr, &size, capacity, 6);

    InsertAtStart(arr, &size, capacity, 2);
    InsertAtStart(arr, &size, capacity, 12);

    InsertAtParticularIndex(arr, &size, capacity, 2, 3);
    InsertAtParticularIndex(arr, &size, capacity, 1, 0);


    // 10 5 6 -> 2 5 6 10 -> 12 5 6 10 2 -> 12 5 3 10 2 6 -> 12 0 3 10 2 6 5

    // printf("%d", size);

    Display(arr, &size);

    return 0;
}