#include <stdio.h>
#include <windows.h>

// Function to reverse the array.
void ReverseArrayUsingFor(int arr[], int size)
{

    for (int index = 0; index < size / 2; index++)
    {
        // Swapping the elements
        int temp = arr[index];
        arr[index] = arr[size - 1 - index];
        arr[size - 1 - index] = temp;
    }
}

int main()
{
    int arr[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 15, 19};

    int size = sizeof(arr) / sizeof(int);

    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }

    printf("\n");

    ReverseArrayUsingFor(arr, size);

    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }

    return 0;
}