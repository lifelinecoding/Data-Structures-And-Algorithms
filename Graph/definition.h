#ifndef DEFINITION_H
#define DEFINITION_H
#include<stdbool.h>

// Structure definition for matrix representation of graph
typedef struct Matrix_Graph{
    int vertices;
    bool isDirected;
    int **matrix;
} Matrix_Graph;

#endif // Closing for DEFINITION_H