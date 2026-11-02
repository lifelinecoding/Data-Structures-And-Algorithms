#ifndef DEFINITION_H
#define DEFINITION_H
#include<stdbool.h>

// Structure definition for matrix representation of graph
typedef struct Matrix_Graph{
    int vertices;
    bool isDirected;
    int **matrix;
} Matrix_Graph;

typedef struct Node{
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct List_Graph{
    int vertices;
    bool isDirected;
    Node **adjList;
} List_Graph;

#endif // Closing for DEFINITION_H