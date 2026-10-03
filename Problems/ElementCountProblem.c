#include <stdio.h>
#include <windows.h>

int main()
{
    // Initializing array
    int arr[] = {
        10,
        20,
        10,
        40,
        20,
        30,
        30,
        10,
        40,
        30,
        10,
        20,
        20,
    };

    // Calculating the length of the array
    int length = sizeof(arr) / sizeof(int);

    // A new array with the same length of element array to track if the element is already counted or not.
    int visited[length];

    // Marking all the indexes to 0(false) in visited array.
    for(int i = 0; i < length; i++){
        visited[i] = 0;
    }

    // Code to count the occurences of the element in the array.
    for (int i = 0; i < length; i++)
    {
        if (visited[i] == 0)
        {
            int count = 1;
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    visited[j] = 1;
                }
            }

            printf("%d occurs %d times.\n", arr[i], count);
        }
    }

    return 0;
}