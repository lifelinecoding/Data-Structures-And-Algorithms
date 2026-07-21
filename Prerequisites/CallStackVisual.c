#include<stdio.h>
#include<windows.h>


int factorial(int num){
    if(num == 0 || num == 1){
        return 1;
    }

    // Sleep(1000);

    return num * factorial(num - 1);
}

int main()
{
    printf("%d", factorial(5));
return 0;
}