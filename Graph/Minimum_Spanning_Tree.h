/*
- In this file Minimum_Spanning_Tree.h the code is written for Adjacency list representation of graph.
- This file contains algorithms for finding minimum spanning tree for a given weighted & connected graph.
- Visit definition.h file to view the structure of graph adjacency list.
*/

#ifndef MINIMUM_SPANNING_TREE
#define MINIMUM_SPANNING_TREE
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include"definition.h"

#ifndef PRIMS_ALGORITHM
#define PRIMS_ALGORITHM

/*
This section contains prim's algorithm implementation.
*/

// Funtion to select next minimum edge in all possible edges.
int minEdge(int key[], bool visited[], int size){
    int minIndex = -1, min = INT_MAX;
    for(int i = 0; i < size; i++){
        if(min > key[i] && !visited[i]){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
// Function to find minimum spanning tree.
void PrimsMinimumSpanningTree(List_Graph *graph, int source){
    if(graph == NULL ) return;
    if(source < 0 || source >= graph->vertices){
        printf("Invalid source.\n");
        return;
    }

    // Allocation of memory for arrays
    bool *visited = (bool*)calloc(sizeof(bool), graph->vertices);   // Tracks which vertices are included in MST.
    int *key = (int*)malloc(sizeof(int) * graph->vertices);         // Tracks all possible edges from vertices included in MST to vertices outside the MST.
    int *parent = (int*)malloc(sizeof(int) * graph->vertices);      // Tracks vertices in MST where index is destination & value is source.

    for(int i = 0; i < graph->vertices; i++) key[i] = INT_MAX;      // Initialize with infinite.

    // Setting starting vertex...
    key[source] = -1;

    // Minimum Spanning Tree has V - 1 edges that is why the above loop will run V - 1 times;
    for(int i = 0; i < graph->vertices - 1; i++){
        // Selecting minimum edge value...
        int destination = minEdge(key, visited, graph->vertices);
        visited[destination] = true;    // Mark it taken in MST.

        Node *current = graph->adjList[destination];
        while(current != NULL){
            if(!visited[current->vertex] && current->weight < key[current->vertex]){
                parent[current->vertex] = destination;
                key[current->vertex] = current->weight;
            }
            current = current->next;
        }
    }

    // Printing the result...
    int totalWeight = 0;
    printf("Edge   | Weight\n");
    for(int i = 1; i < graph->vertices; i++){
        if(i == source) continue;
        printf("%d -> %d | %d\n", parent[i], i, key[i] );
        totalWeight += key[i];
    }
    printf("Total Weight of MST: %d\n", totalWeight);

    // Free the allocated memory.
    free(parent);
    free(visited);
    free(key);
}

#endif      // Closing for PRIMS_ALGORITHM
#endif      // Closing for MINIMUM_SPANNING_TREE