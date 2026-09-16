#include<stdio.h>
#include<windows.h>

// Node definition
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

// Type definition
typedef struct Node Node;


// Function to insert a new node at the starting of doubly linked list.
Node* InsertAtPosition(Node* head, int position, int data){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed for new node.\n");
        return head;
    }

    //Checking position validity.
    if(position <= 0){
        printf("Invalid Position.\n");
        return head;
    }

    // Checking if no node exist on linked list.
    if(current == NULL){
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    // If insertion is happening at first position
    if(position == 1){
        newNode->data = data;
        newNode->next = current;
        current->prev = newNode;
        newNode->prev = NULL;
        return newNode;
    }

    // Traversing the list upto the position.
    for(int i = 1; i < position -1 && current->next != NULL; i++){
        current = current->next;
    }

    // Adding new node at the correct position
    newNode->data =data;
    newNode->next = current->next;
    if(current->next != NULL){
        (current->next)->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
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

    head = InsertAtPosition(head, 2, 4);
    head = InsertAtPosition(head, 2, 3);
    head = InsertAtPosition(head, 3, 9);
    head = InsertAtPosition(head, 1, 7);
    head = InsertAtPosition(head, 8, 2);
    head = InsertAtPosition(head, 3, 2);
    head = InsertAtPosition(head, -4, 4);
    TraverseUsingHead(head);
return 0;
}