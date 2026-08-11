#include <stdio.h>
#include <windows.h>

// Binary Search Algorithm
int BinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Edge Case
        if (arr[low] == target)
        {
            return low;
        }

        if (arr[high] == target)
        {
            return high;
        }

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 15, 19};

    int size = sizeof(arr) / sizeof(int);
    int target = 20;

    int result = BinarySearch(arr, size, target);

    if(result < 0){
        printf("Element not found!");
    }else{
        printf("Element %d found at index %d\n", target, result);
    }

    return 0;
}