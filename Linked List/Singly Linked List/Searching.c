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

// Searching a element.
int Search(Node *head, int element)
{
    Node *current = head;

    while (current != NULL)
    {
        if(current->data == element){
            printf("%d is present in the linked list.\n", element);
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *first = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));


    // Assigning values to node
    head->data = 1;
    first->data = 2;
    second->data = 3;
    third->data = 4;
    fourth->data = 5;
    fifth->data = 6;

    // Connection
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    int result = Search(head, 10);
    if(result == 0){
        printf("Element is not present!");
    }

    // Free Memory location
    free(head);
    free(first);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}