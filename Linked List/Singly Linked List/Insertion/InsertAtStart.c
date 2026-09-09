#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


// Node definition
struct Node
{
    int data;
    struct Node *next;
};

// Type definition
typedef struct Node Node;

// Function to insert a new node at the starting of the linked list.
Node* InsertAtStart(Node* head, int data){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return head;
    }

    if(current == NULL){
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    newNode->data = data;
    newNode->next = current;
    return newNode;
}

void Traverse(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    Node *head = NULL;

    head = InsertAtStart(head, 5);
    head = InsertAtStart(head, 3);
    head = InsertAtStart(head, 7);
    head = InsertAtStart(head, 0);
    Traverse(head);
return 0;
}