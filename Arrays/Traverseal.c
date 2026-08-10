#include<stdio.h>
#include<windows.h>

void Traverse(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int size = sizeof(arr) / sizeof(int);

    Traverse(arr, size);

return 0;
}