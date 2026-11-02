#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include"Adjacency_Matrix_Graph.h"


int main(){
    Matrix_Graph *graph = NULL;
    graph = createGraph(5, false);
    
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 3, 1);

    printf("%d ", isEdgeExist(graph, 2, 3));
    printf("%d ", neighbors(graph, 3));
    
    removeEdge(graph, 3, 4);
    printf("%d ", degree(graph, 3));

    displayAdjacencyMatrix(graph);
    DepthFirstSearchMatrix(graph, 0);
    BreadthFirstSearchMatrix(graph, 2);
    freeGraph(graph);
return 0;
}