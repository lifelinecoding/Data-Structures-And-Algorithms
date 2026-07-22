#include <stdio.h>
#include <windows.h>

int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main()
{
    int result = factorial(5);
    printf("%d", result);
    return 0;
}