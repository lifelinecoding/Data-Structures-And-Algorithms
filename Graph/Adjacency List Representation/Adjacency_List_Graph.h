#ifndef ADJACENCY_LIST_GRAPH
#define ADJACENCY_LIST_GRAPH
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"../definition.h"

//! Utility functions for instertion and deletion in List

// Function for insertion
Node* InsertInAdjacencyList(Node* head, int destination, int weight){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->vertex = destination;
    newNode->weight = weight;
    if(current == NULL){
        newNode->next = NULL;
        return newNode;
    }
    newNode->next = current;
    return newNode;
}

// Function to delete a node from a linked list based on data.
Node *DeleteInAdjacencyList(Node *head, int vertex){
    Node *current = head;
    Node *Next = head->next;
    // Check if their is any node in linked list or not.
    if(current == NULL) return current;

    // Checking if user want to delete the head.
    if (current->vertex == vertex)    {
        free(current);
        return Next;
    }

    // Traversing the list until the data is found
    while (Next != NULL){
        if (Next->vertex == vertex){
            current->next = Next->next;
            free(Next);
            return head;
        }
        current = current->next;
        Next = Next->next;
    }

    return head;
}

// Create Graph function(Vertices(int), isDirected(boolean))
List_Graph *createGraph(int vertices, bool isDirected){
    if(vertices <= 0){
        printf("Invalid number of vertices.\n");
        return NULL;
    }
    // Memory allocation for graph.
    List_Graph *graph = (List_Graph*)malloc(sizeof(List_Graph));
    graph->vertices = vertices;
    graph->isDirected = isDirected;

    graph->adjList = (Node**)malloc(sizeof(Node*));
    for(int i = 0; graph->vertices; i++) graph->adjList[i] = NULL;
    return graph;
}
// Free graph function(graph g)
void freeGraph(List_Graph *graph){
    if(graph == NULL) return;
    for(int i = 0; i < graph->vertices; i++){
        Node *current = graph->adjList[i];
        while (current != NULL){
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjList);
    free(graph);
}
// Function to add a new edge(graph, source, destination, weight)
void addEdge(List_Graph *graph, int source, int destination, int weight){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return;
    }
    // Adding a new edge.
    graph->adjList[source] = InsertInAdjacencyList(graph->adjList[source], destination, weight);

    //Checking is the graph is directed or not for bi-directional edges.
    if(!graph->isDirected) graph->adjList[destination] = InsertInAdjacencyList(graph->adjList[destination], source, weight);
}
// Function to remove edge(graph, source, destination)
void removeEdge(List_Graph *graph, int source, int destination){
    if(graph == NULL) return;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return;
    }
    graph->adjList[source] = DeleteInAdjacencyList(graph->adjList[source], destination);

    //Checking is the graph is directed or not for bi-directional edges.
    if(!graph->isDirected) graph->adjList[destination] = DeleteInAdjacencyList(graph->adjList[destination], source);
}
// Function to check if an edge exist between two nodes (graph, source, destination)
//TODO: Function to get weight of an edge (graph, source, destination)
//TODO: Function to get all neighbors of a vertex (graph, vertex);
//TODO: Funtion to get degree of a vertex (graph, vertex).
//TODO: Function to display Adjacency List of the graph (Graph).
//TODO: Graph traversal using breadth first search.
//TODO: Graph traversal using depth first search.

#endif // CLosing for ADJACENCY_LIST_GRAPH