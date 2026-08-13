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
    InsertAtEnd(arr, &size, capacity, 0);
    InsertAtEnd(arr, &size, capacity, 7);
    InsertAtEnd(arr, &size, capacity, 17);
    InsertAtEnd(arr, &size, capacity, 8);
    InsertAtEnd(arr, &size, capacity, 6);
    InsertAtEnd(arr, &size, capacity, 3);
    InsertAtEnd(arr, &size, capacity, 1);
    InsertAtEnd(arr, &size, capacity, 100);

    // printf("%d", size);

    Display(arr, &size);

    return 0;
}