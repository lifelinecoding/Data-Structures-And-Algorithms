#include <stdio.h>
#include <windows.h>

int main()
{
    int matrix[3][3][4] = {
        {{1, 2, 3, 5},
         {4, 5, 6, 5},
         {7, 8, 9, 5}},
        {{10, 11, 12, 5},
         {13, 14, 15, 5},
         {16, 17, 18, 5}},
        {{19, 20, 21, 5},
         {22, 23, 24, 5},
         {25, 26, 27, 5}}};

    int dimension1 = sizeof(matrix) / sizeof(matrix[0]);
    int dimension2 = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int dimension3 = sizeof(matrix[0][0]) / sizeof(matrix[0][0][0]);

    // printf("%d %d %d", dimension1, dimension2, dimension3);

    for (int i = 0; i < dimension1; i++)
    {
        for (int j = 0; j < dimension2; j++)
        {
            for (int k = 0; k < dimension3; k++)
            {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}