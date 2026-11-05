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

// Function to search an element in linked list.
bool SearchInAdjacencyList(Node *head, int vertex){
    Node *current = head;
    while (current != NULL){
        if(current->vertex == vertex){
            return true;
        }
        current = current->next;
    }
    return false;
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

    graph->adjList = (Node**)malloc(sizeof(Node*) * graph->vertices);
    if(graph->adjList == NULL){
        free(graph);
        return NULL;
    }
    for(int i = 0; i < graph->vertices; i++) graph->adjList[i] = NULL;
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
bool isEdgeExist(List_Graph *graph, int source, int destination){
    if(graph == NULL) return false;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return false;
    }

    return SearchInAdjacencyList(graph->adjList[source], destination);
}
// Function to get weight of an edge (graph, source, destination)
int weight(List_Graph *graph, int source, int destination){
    if(graph == NULL) return 0;
    if(source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices){
        printf("Invalid source or destination.\n");
        return 0;
    }
    if(isEdgeExist(graph, source, destination)){
        Node *current = graph->adjList[source];
        while(current != NULL){
            if(current->vertex == destination){
                return current->weight;
            }
            current = current->next;
        }
    }
}
// Function to get all neighbors of a vertex (graph, vertex);
void neighbors(List_Graph *graph, int vertex){
    if(graph == NULL) return;
    if(vertex < 0 || vertex >= graph->vertices){
        printf("Invalid source or destination.\n");
        return;
    }

    Node *current = graph->adjList[vertex];
    while(current != NULL){
        printf("%d ", current->vertex);
        current = current->next;
    }
}
// Funtion to get degree of a vertex (graph, vertex).
int inDegree(List_Graph *graph, int vertex){
    int indegree = 0;
    if(graph == NULL) return 0;
    if(vertex < 0 || vertex >= graph->vertices){
        printf("Invalid source or destination.\n");
        return 0;
    }
    for(int i = 0; i < graph->vertices; i++){
        if(SearchInAdjacencyList(graph->adjList[i], vertex)) indegree++;
    }
    return indegree;
}

int outDegree(List_Graph *graph, int vertex){
    int outdegree = 0;
    if(graph == NULL) return 0;
    if(vertex < 0 || vertex >= graph->vertices){
        printf("Invalid source or destination.\n");
        return 0;
    }
    Node * current = graph->adjList[vertex];
    while(current != NULL){
        outdegree++;
        current = current->next;
    }
    return outdegree;
}

int degree(List_Graph *graph, int vertex){
    int deg = 0;
    if(graph == NULL) return 0;
    if(vertex < 0 || vertex >= graph->vertices){
        printf("Invalid source or destination.\n");
        return 0;
    }
    if(!graph->isDirected){
        Node *current = graph->adjList[vertex];
        while(current != NULL){
                deg++;
            current = current->next;
        }
        return deg;
    }
    return inDegree(graph, vertex) + outDegree(graph, vertex);
}
// Function to display Adjacency List of the graph (Graph).
void displayAdjacencyList(List_Graph *graph){
    if(graph == NULL) return;
    for(int i = 0; i < graph->vertices; i++){
        Node *current = graph->adjList[i];
        printf("%d |", i);
        while(current != NULL){
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}
//TODO: Graph traversal using breadth first search.
//TODO: Graph traversal using depth first search.

#endif // CLosing for ADJACENCY_LIST_GRAPH