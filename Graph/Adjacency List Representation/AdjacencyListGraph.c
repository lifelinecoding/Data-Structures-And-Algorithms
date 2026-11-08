#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Adjacency_List_Graph.h"
#include"../definition.h"
#include"../Minimum_Spanning_Tree.h"

int main(){
    List_Graph *graph = NULL;
    graph = createGraph(5, false);
    if(graph == NULL) printf("Hello");
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 3, 4, 5);

    // removeEdge(graph, 3, 4);
    // printf("%d ", isEdgeExist(graph, 1, 4));

    // displayAdjacencyList(graph);
    // DepthFirstSearchList(graph, 2);
    // printf("\n");
    // BreadthFirstSearchList(graph, 2);

    PrimsMinimumSpanningTree(graph, 1);
    freeGraph(graph);
return 0;
}