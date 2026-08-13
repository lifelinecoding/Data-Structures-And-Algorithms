#include <stdio.h>
#include <windows.h>

// Algorithm to find the element whose occurence is odd.
int OddOccurence(int arr[], int size)
{
    int result = arr[0];

    for (int index = 1; index < size; index++)
    {
        result = result ^ arr[index];
    }

    return result;
}

int main()
{
    int arr[] = {2, 5, 5, 7, 5, 9, 5, 7, 7, 2, 9, 7, 5};

    int size = sizeof(arr) / sizeof(int);

    int result = OddOccurence(arr, size);

    printf("%d occurs odd times in the array.", result);

    return 0;
}