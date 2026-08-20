#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Inserting a new element at the starting.
void InsertAtStart(int arr[], int *size, int capacity, int newItem)
{
    if (*size >= capacity)
    {
        printf("Array is full.\n");
    }
    else
    {
        for (int index = *size; index >= 0; index--)
        {
            arr[index] = arr[index - 1];
        }

        arr[0] = newItem;
        *size = *size + 1;
    }
}

// Inserting a new element at the particular index.

void InsertAtParticularIndex(int arr[], int *size, int capacity, int index, int newItem){
    if (*size >= capacity)
    {
        printf("Array is full.\n");
    }
    else if(index > *size){
        printf("Invalid index.\n");
    }
    else {
        for (int idx = *size; idx >= index; idx--)
        {
            arr[idx] = arr[idx - 1];
        }

        arr[index] = newItem;
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

    InsertAtStart(arr, &size, capacity, 1);
    InsertAtStart(arr, &size, capacity, 2);
    InsertAtStart(arr, &size, capacity, 3);
    InsertAtStart(arr, &size, capacity, 4);
    InsertAtStart(arr, &size, capacity, 5);
    InsertAtStart(arr, &size, capacity, 6);

    InsertAtParticularIndex(arr, &size, capacity, 3, 10);
    InsertAtParticularIndex(arr, &size, capacity, 6, 9);

    //  6 -> 5 -> 4 -> 3 -> 2 -> 1
    //  6 -> 5 -> 4 -> 10 -> 3 -> 2 -> 1


    Display(arr, &size);

    return 0;
}