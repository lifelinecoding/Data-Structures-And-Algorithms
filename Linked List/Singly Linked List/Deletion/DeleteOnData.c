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
Node *DeleteOnData(Node *head, int data)
{
    Node *current = head;
    Node *Next = head->next;

    // Check if their is any node in linked list or not.
    if(current == NULL){
        printf("No node exist in the list\n");
        return head;
    }

    // Checking if user want to delete the head.
    if (current->data == data)
    {
        free(current);
        return Next;
    }

    // Traversing the list until the data is found
    while (Next != NULL)
    {
        if (Next->data == data)
        {
            current->next = Next->next;
            free(Next);
            return head;
        }
        current = current->next;
        Next = Next->next;
    }

    printf("Data does not exist in this linked list\n");
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
    // Node* head = NULL;
    Node *head = (Node *)malloc(sizeof(head));
    Node *first = (Node *)malloc(sizeof(head));
    Node *second = (Node *)malloc(sizeof(head));
    Node *third = (Node *)malloc(sizeof(head));

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

    head = DeleteOnData(head, 2);
    head = DeleteOnData(head, 5);
    head = DeleteOnData(head, 1);
    Traverse(head);

    // Free the memory location
    free(head);
    free(first);
    free(second);
    free(third);
    return 0;
}