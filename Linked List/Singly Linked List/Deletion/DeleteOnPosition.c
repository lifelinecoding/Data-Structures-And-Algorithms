#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// Node definition
struct Node
{
    int data;
    struct Node *next;
};

// Type definition
typedef struct Node Node;

// Function to delete a node from a linked list at a specified position.
Node *DeleteAtPosition(Node *head, int position)
{
    Node *current = head;
    Node *Next = head->next;
    int i;

    // Check if position is negative or not.
    if (position < 0)
    {
        printf("Invalid position\n");
        return head;
    }

    // Check if their is any node in linked list or not.
    if(current == NULL){
        printf("No node exist in the list\n");
        return head;
    }

    // Deleting the first node.
    if(position == 1){
        free(current);
        return Next;
    }

    // Traversing the list upto the specified position to delete the node.
    for (i = 1; i < position - 1 && Next != NULL; i++)
    {
        current = current->next;
        Next = Next->next;
    }

    //  Check position
    if( i != position -1){
        printf("Invalid Position\n");
        return head;
    }

    current->next = Next->next;
    free(Next);
    return head;
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
    Node* head = (Node*)malloc(sizeof(head));
    Node* first = (Node*)malloc(sizeof(head));
    Node* second = (Node*)malloc(sizeof(head));
    Node* third = (Node*)malloc(sizeof(head));

    // Assigning values to node
    head->data = 1;
    first->data = 2;
    second->data = 3;
    third->data = 4;

    // Connection
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    head = DeleteAtPosition(head, 2);
    head = DeleteAtPosition(head, 1);
    head = DeleteAtPosition(head, 4);       // Invalid position
    Traverse(head);
    return 0;
}