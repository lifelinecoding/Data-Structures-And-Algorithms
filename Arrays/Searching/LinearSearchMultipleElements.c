#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Result
{
    int *arr;
    int capacity;
    int size;
    int status;
};

// Type definition od structure
typedef struct Result Result;

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

// Function to search the element in array with multiple occurence.
Result LinearSearchWithMultipleElements(int arr[], int capacity, int target)
{
    Result result;
    result.arr = (int *)malloc(sizeof(int) * capacity);
    result.size = 0;
    result.capacity = capacity;
    result.status = 0;
    for (int index = 0; index < capacity; index++)
    {
        if (arr[index] == target)
        {
            InsertAtEnd(result.arr, &result.size, result.capacity, index);
            result.status = 1;
        }
    }

    return result;
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
    int arr[] = {1, 6, 2, 3, 1, 6, 4, 5, 6, 7, 8, 1, 9, 6, 10};

    int capacity = sizeof(arr) / sizeof(int);
    int target = 6;

    Result result = LinearSearchWithMultipleElements(arr, capacity, target);

    if (result.status == 0)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element %d found at index: ", target);
        Display(result.arr, &result.size);
    }

    free(result.arr);

    return 0;
}