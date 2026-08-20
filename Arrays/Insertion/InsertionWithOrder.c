#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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

    // 1

    Display(arr, &size);

    return 0;
}