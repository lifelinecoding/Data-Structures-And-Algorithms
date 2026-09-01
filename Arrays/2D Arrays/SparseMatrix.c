#include <stdio.h>
#include <windows.h>

struct SparseMatrix
{
    int row;
    int column;
    int value;
};

// Type Definition
typedef struct SparseMatrix SparseMatrix;

int main()
{
    int matrix[3][3] =
        {
            {0, 2, 0},
            {4, 0, 0},
            {0, 8, 0}};

    int count = 0;
    int dimension1 = sizeof(matrix) / sizeof(matrix[0]);
    int dimension2 = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    for (int i = 0; i < dimension1; i++)
    {
        for (int j = 0; j < dimension2; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }

    SparseMatrix Sparse[count];
    int tracker = 0;
    for (int i = 0; i < dimension1; i++)
    {
        for (int j = 0; j < dimension2; j++)
        {
            if (matrix[i][j] != 0)
            {
                Sparse[tracker].row = i;
                Sparse[tracker].column = j;
                Sparse[tracker].value = matrix[i][j];
                tracker++;
            }
        }
    }

    for (int index = 0; index < count; index++)
    {
        printf("%d %d %d\n", Sparse[index].row, Sparse[index].column, Sparse[index].value);
    }

    return 0;
}