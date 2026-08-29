#include <stdio.h>
#include <windows.h>

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int dimension1 = sizeof(matrix)/sizeof(matrix[0]);
    int dimension2 = sizeof(matrix[0])/sizeof(matrix[0][0]);

    int result[dimension1][dimension2];

    for(int i = 0; i < dimension1; i++){
        for(int j = 0; j < dimension2; j++){
            // Transpose
            result[j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < dimension1; i++){
        for(int j = 0; j < dimension2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }



    return 0;
}