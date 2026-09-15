#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

// Node definition
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

// Type definition
typedef struct Node Node;

// Function to insert a new node at the end of doubly linked list.

Node* IntsertAtEnd(Node* head, int data){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed for new node.\n");
        return head;
    }

    // Checking if no node exist in list.
    if(head == NULL){
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    while(current->next != NULL){
        current = current->next;
    }

    // printf("Hello\n");
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
    // printf("Hello\n");
    return head;
}


// Travere using head
void TraverseUsingHead(Node* head){
    Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }   
}

int main()
{
    Node* head = NULL;
    head = IntsertAtEnd(head, 5);
    head = IntsertAtEnd(head, 3);
    head = IntsertAtEnd(head, 2);
    head = IntsertAtEnd(head, 1);
    head = IntsertAtEnd(head, 4);
    head = IntsertAtEnd(head, 6);
    TraverseUsingHead(head);
return 0;
}