#include <stdio.h>
#include <windows.h>

int main()
{
    // int matrixA[3][3] =
    //     {
    //         {1, 2, 3},
    //         {4, 5, 6},
    //         {7, 8, 9}};

    // int matrixB[3][3] =
    //     {
    //         {5, 3, 8},
    //         {14, 5, 43},
    //         {6, 7, 9}};

    // int rowA = sizeof(matrixA) / sizeof(matrixA[0]);
    // int columnA = sizeof(matrixA[0]) / sizeof(matrixA[0][0]);

    // int rowB = sizeof(matrixB) / sizeof(matrixB[0]);
    // int columnB = sizeof(matrixB[0]) / sizeof(matrixB[0][0]);

    int rowA, columnA;
    int rowB, columnB;

    printf("Enter the dimension of matrix A: ");
    scanf("%d %d", &rowA, &columnA);

    printf("Enter the dimension of matrix B: ");
    scanf("%d %d", &rowB, &columnB);

    if (columnA != rowB)
    {
        printf("Matrix multiplication is not possible\n");
    }
    else
    {

        int matrixA[rowA][columnA];
        int matrixB[rowB][columnB];

        // Taking user input for matrix A
        printf("--------------- Enter the values for Matrix A ---------------\n");
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < columnA; j++)
            {
                printf("Enter the value at %d %d: ", i + 1, j + 1);
                scanf("%d", &matrixA[i][j]);
            }
        }
        printf("--------------- Enter the values for Matrix B ---------------\n");
        // Taking user input for matrix B
        for (int i = 0; i < rowB; i++)
        {
            for (int j = 0; j < columnB; j++)
            {
                printf("Enter the value at %d %d: ", i + 1, j + 1);
                scanf("%d", &matrixB[i][j]);
            }
        }

        int result[rowA][columnB];
        int commonDimension = columnA;

        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < columnB; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < commonDimension; k++)
                {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        // Result
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < columnB; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}