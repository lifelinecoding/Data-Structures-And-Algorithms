#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Queue{
    Node *front;
    Node *rear;
    Node *list;
};

typedef struct Queue Queue;

// Function that initialize an empty queue.
void initialize(Queue *que){
    que->list = NULL;
    que->front = NULL;
    que->rear = NULL;
}

// Enqueue operation
void enqueue(Queue *que, int newItem){

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    // if queue is empty.
    if (que->list == NULL){
        newNode->data = newItem;
        newNode->next = NULL;
        que->front = newNode;
        que->rear = newNode;
        que->list = que->front;
        return;
    }

    newNode->data = newItem;
    newNode->next = NULL;
    que->rear->next = newNode;
    que->rear = newNode;
    return;
}

// Dequeue Operation
int dequeue(Queue *que){

    if (que->list == NULL){
        printf("Queue is empty!\n");
    }
    else{
        int value = que->front->data;

        // If queue has only one element.
        if (que->front == que->rear){
            free(que->front);
            initialize(que);
        }
        else{
            // If queue has more than one element.
            Node *temp = que->front;
            que->front = temp->next;
            que->list = que->front;
            free(temp);
        }
        return value;
    }
}

// Function to display the elements of the queue.
void Display(Queue *que){
    Node *start = que->front;
    Node *end = que->rear;

    while (1){
        printf("%d ", start->data);
        if (start == end)
            break;
        start = start->next;
    }
}

int main(){
    Queue que;
    initialize(&que);

    enqueue(&que, 5);
    enqueue(&que, 15);
    enqueue(&que, 25);
    enqueue(&que, 35);
    enqueue(&que, 45);
    enqueue(&que, 55);
    enqueue(&que, 65);

    dequeue(&que);
    dequeue(&que);
    dequeue(&que);

    Display(&que);

    return 0;
}