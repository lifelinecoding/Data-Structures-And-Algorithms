#ifndef ADJACENCY_MATRIX_GRAPH
#define ADJACENCY_MATRIX_GRAPH
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"../definition.h"

// Create Graph function(Vertices(int), isDirected(boolean))
Matrix_Graph * createGraph(int vertices, bool isDirected){
    if(vertices <= 0){
        printf("Invalid number of vertices.\n");
        return NULL;
    }
    // Memory allocation for graph.
    Matrix_Graph *graph = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    graph->vertices = vertices;
    graph->isDirected = isDirected;

    graph->matrix = (int**)malloc(sizeof(int*)*graph->vertices);
    for(int i = 0; i < graph->vertices; i++){
        graph->matrix[i] = (int*)calloc(sizeof(int),graph->vertices);
    }
    return graph;
}
//Free graph function(graph g)
void freeGraph(Matrix_Graph *graph){
    if(graph == NULL) return;
    for(int i = 0; i < graph->vertices; i++) free(graph->matrix[i]);
    free(graph->matrix);
    free(graph);
}
//Function to add a new edge(graph, source, destination, weight)
void addEdge(Matrix_Graph *graph, int source, int destination, int weight){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return;
    }
    // Adding a new edge.
    graph->matrix[source][destination] = weight;

    // Checking the graph is directed or not for bi-directional edges.
    if(!graph->isDirected) graph->matrix[destination][source] = weight;
}
// Function to add a remove edge(graph, source, destination)
void removeEdge(Matrix_Graph *graph, int source, int destination){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return;
    }
    graph->matrix[source][destination] = 0;

    // Checking the graph is directed or not for bi-directional edges.
    if(!graph->isDirected) graph->matrix[destination][source] = 0;
}
// Function to check if an edge exist between two nodes (graph, source, destination)
bool isEdgeExist(Matrix_Graph *graph, int source, int destination){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return false;
    }
    return graph->matrix[source][destination] != 0;
}
// Function to get weight of an edge (graph, source, destination)
int weight(Matrix_Graph *graph, int source, int destination){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return 0;
    }

    return graph->matrix[source][destination];
}
// Function to get all neighbors of a vertex (graph, vertex);
int neighbors(Matrix_Graph *graph, int vertex){
    int neighbor = 0;
    if(graph == NULL) return 0;
    if(vertex < 0 || vertex >= graph->vertices){
        printf("Invalid vertex.\n");
        return 0;
    }
    for(int i = 0; i < graph->vertices; i++){
        if(graph->matrix[vertex][i] != 0) neighbor++;
    }
    return neighbor;
}
// TODO: Funtion to get degree of a vertex (graph, vertex).
// TODO: Function to display adjacency matrix of the graph(graph).
// TODO: Graph traversal using breadth first search.
// TODO: Graph traversal using depth first search.

#endif // Closing for ADJACENCY_MATRIX_GRAPH