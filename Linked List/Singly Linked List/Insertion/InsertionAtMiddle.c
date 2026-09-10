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

// Function to insert a new node at the middle of the linked list.
Node *InsertAtMiddle(Node *head, int position, int data)
{
    Node *current = head;
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(position < 0){
        printf("Invalid position\n");
        return head;
    }

    // Memory is allocated for new node or not.
    if (newNode == NULL)
    {
        printf("Memory allocation for new node is failed!\n");
        return head;
    }

    // Checking is the list exist or not
    if (current == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    // Travering the list upto the correct insertion position.
    for (int i = 1; i < position - 1 && current->next != NULL; i++)
    {
        current = current->next;
        // printf("hello\n");
    }

    // Add the node to the linked list.
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
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
    Node *head = NULL;
    // Node* head = (Node*)malloc(sizeof(head));
    // Node* first = (Node*)malloc(sizeof(head));
    // Node* second = (Node*)malloc(sizeof(head));
    // Node* third = (Node*)malloc(sizeof(head));

    // // Assigning values to node
    // head->data = 1;
    // first->data = 2;
    // second->data = 3;
    // third->data = 4;

    // // Connection
    // head->next = first;
    // first->next = second;
    // second->next = third;
    // third->next = NULL;

    head = InsertAtMiddle(head, 5, 6);
    head = InsertAtMiddle(head, 2, 4);
    head = InsertAtMiddle(head, 4, 7);
    head = InsertAtMiddle(head, 2, 1);
    Traverse(head);
    return 0;
}