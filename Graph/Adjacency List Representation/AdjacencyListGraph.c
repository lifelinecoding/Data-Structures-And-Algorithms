#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Adjacency_List_Graph.h"
#include"../definition.h"

int main(){
    List_Graph *graph = NULL;
    graph = createGraph(5, false);
    if(graph == NULL) printf("Hello");
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 3, 4, 1);

    // removeEdge(graph, 3, 4);
    // printf("%d ", isEdgeExist(graph, 1, 4));

    // displayAdjacencyList(graph);
    DepthFirstSearchList(graph, 1);
    freeGraph(graph);
return 0;
}