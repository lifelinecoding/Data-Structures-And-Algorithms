#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int CharacterFrequency(char string[], int size)
{
    int *visited = (int *)calloc(size, sizeof(int));
    if (visited == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    for (int i = 0; i <= size; i++)
    {
        char ch = string[i];
        int count = 0;
        int flag = 0;
        if (visited[i] != 1 && string[i] != ' ')
        {
            count++;
            visited[i] = 1;
            flag = 1;
        }

        if(string[i] == ' '){
            continue;
        }

        for (int j = i + 1; j <= size; j++)
        {
            if ((string[i] == string[j]) && visited[j] != 1)
            {
                count++;
                visited[j] = 1;
            }
        }

        if(flag){
            printf("%c - %d\n", string[i], count);
        }
    }
}

int main()
{
    char string[] = "Hello World";
    int size = strlen(string);
    CharacterFrequency(string, size);
    return 0;
}