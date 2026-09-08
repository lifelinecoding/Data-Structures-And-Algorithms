#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Node definition
struct Node
{
    int data;
    struct Node *next;
};

// Type definition
typedef struct Node Node;

Node* InsertAtEnd(Node *head, int data)
{
    Node *current = head;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation for new node is failed!\n");
        return 0;
    }

    // Checking is head node is NULL.
    if (head == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    // Tracking the last position of the linked list.
    while (current->next != NULL)
    {
        current = current->next;
    }

    newNode->data = data;
    current->next = newNode;
    newNode->next = NULL;
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
    // Node *head = (Node*)malloc(sizeof(Node));
    // head->data = 9;
    // head->next = NULL;

    Node *head = NULL;

    head = InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    InsertAtEnd(head, 7);
    InsertAtEnd(head, 8);
    InsertAtEnd(head, 9);
    InsertAtEnd(head, 10);
    InsertAtEnd(head, 11);

    Traverse(head);

    return 0;
}