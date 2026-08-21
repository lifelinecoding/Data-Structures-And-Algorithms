#include <stdio.h>
#include <windows.h>

void Delete(int arr[], int index, int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty.\n");
    }
    else if (*size <= index)
    {
        printf("Invalid index.\n");
    }
    else
    {
        for(int idx = index; idx < *size; idx++){
            arr[idx] = arr[idx + 1];
        }
        *size = *size - 1;
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
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 6;
    arr[3] = 4;
    arr[4] = 9;
    int size = 5;

    Display(arr, &size);

    Delete(arr, 2, &size);
    Delete(arr, 1, &size);
    printf("\n");
    Display(arr, &size);

    free(arr);

    return 0;
}