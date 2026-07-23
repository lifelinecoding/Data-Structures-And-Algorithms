#include<stdio.h>
#include<windows.h>
#include<malloc.h>


int main()
{
    // Dynamic memory allocaion using malloc

    int* ptr = (int*)malloc(sizeof(int) * 10);

    ptr[5] = 67;
    
    for(int i = 0; i< 10; i++){
        printf("%d ", *(ptr + i));
    }

    // Dynamic memory allocaion using calloc method

    int* ptrC = (int*)calloc(sizeof(int), 10);

    ptrC[5] = 67;
    
    for(int i = 0; i< 10; i++){
        printf("%d ", *(ptrC + i));
    }


    // Dynamic memory reallocaion using realloc method

    int* ptrR = (int*)realloc(ptr, sizeof(int) * 20);

    
    for(int i = 0; i< 20; i++){
        printf("%d ", *(ptrR + i));
    }

    // Free all the space once the work has been completed

    free(ptr);
    free(ptrC);
    free(ptrR);
return 0;
}