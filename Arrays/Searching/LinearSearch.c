#include <stdio.h>
#include <windows.h>

int LinearSearch(int arr[], int size, int target)
{
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == target)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(int);
    int target = 11;

    int result = LinearSearch(arr, size, target);

    if (result < 0)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element %d found at index %d\n", target, result);
    }

    return 0;
}