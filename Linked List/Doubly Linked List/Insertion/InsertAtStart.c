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
Node* InsertAtStart(Node* head, int data){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation for new node is failed.\n");
        return head;
    }

    if(current == NULL){
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    newNode->data = data;
    newNode->next = current;
    current->prev = newNode;
    newNode->prev = NULL;
    return newNode;
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
    head = InsertAtStart(head, 5);
    head = InsertAtStart(head, 7);
    head = InsertAtStart(head, 9);
    head = InsertAtStart(head, 2);
    head = InsertAtStart(head, 1);
    head = InsertAtStart(head, 3);
    TraverseUsingHead(head);
return 0;
}