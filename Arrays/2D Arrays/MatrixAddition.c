#include<stdio.h>
#include<windows.h>


int main()
{
    int matrixA[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[3][3] = 
    {
        {5, 3, 8},
        {14, 5, 43},
        {6, 7, 9}
    };

    int dimensionA1 = sizeof(matrixA)/sizeof(matrixA[0]);
    int dimensionA2 = sizeof(matrixA[0])/sizeof(matrixA[0][0]);

    int dimensionB1 = sizeof(matrixB)/sizeof(matrixB[0]);
    int dimensionB2 = sizeof(matrixB[0])/sizeof(matrixB[0][0]);

    if((dimensionA1 == dimensionB1) && (dimensionA2 == dimensionB2)){

        int result[dimensionA1][dimensionA2];

        for(int i = 0; i < dimensionA1; i++){
            for(int j = 0; j < dimensionA2; j++){
                // Matrix Addition core logic.
                result[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }

        for(int i = 0; i < dimensionA1; i++){
            for(int j = 0; j < dimensionA2; j++){
               printf("%d ",result[i][j] ); 
            }
            printf("\n");
        }

    }else{
        printf("Matrix addition is not possible");
    }


return 0;
}