#include <stdio.h>
#include <windows.h>

int BinarySearch(int arr[], int low, int high, int target)
{

    int mid = (low + high) / 2;
    // Edge case
    if (arr[low] == target)
    {
        return low;
    }

    if (arr[high] == target)
    {
        return high;
    }

    // Base case
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        BinarySearch(arr, mid + 1, high, target);
    }
    else
    {
        BinarySearch(arr, low, mid - 1, target);
    }
}

int main()
{
    int arr[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 15, 19};

    int size = sizeof(arr) / sizeof(int);
    int target = 12;

    int result  = BinarySearch(arr, 0, size - 1, target);

    if(result < 0){
        printf("Element not found");
    }else{
        printf("Element %d found at %d\n", target, result);
    }

    return 0;
}