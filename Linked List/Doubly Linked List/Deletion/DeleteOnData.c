#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// Node definition
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Type definition
typedef struct Node Node;

// Function to delete a node at specified position in doublly linked list.
Node *DeleteOnData(Node *head, int data)
{
    Node *current = head;
    Node *Next = NULL;

    if (current == NULL)
    {
        printf("No node exist for deletion.\n");
        return head;
    }

    if (current->data == data)
    {
        if (current->next != NULL)
        {
            Next = current->next;
            (current->next)->prev = NULL;
        }
        free(current);
        return Next;
    }

    Next = current->next;
    while (Next != NULL)
    {
        if (Next->data != data)
        {
            current = current->next;
            Next = Next->next;
            continue;
        }
        else
        {
            current->next = Next->next;
            if (Next->next != NULL)
            {
                (Next->next)->prev = current;
            }
            free(Next);
        }

        return head;
    }
    printf("Data is not present in the list\n");
    return head;
}

// Travere using head
void TraverseUsingHead(Node *head)
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
    Node *head = (Node *)malloc(sizeof(Node));
    Node *first = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));
    Node *sixth = (Node *)malloc(sizeof(Node));
    Node *seventh = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));

    head->data = 1;
    first->data = 2;
    second->data = 3;
    third->data = 4;
    fourth->data = 5;
    fifth->data = 6;
    sixth->data = 7;
    seventh->data = 8;
    tail->data = 9;

    // Connection
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = tail;
    tail->next = NULL;

    // Previous node connection
    tail->prev = seventh;
    seventh->prev = sixth;
    sixth->prev = fifth;
    fifth->prev = fourth;
    fourth->prev = third;
    third->prev = second;
    second->prev = first;
    first->prev = head;
    head->prev = NULL;

    TraverseUsingHead(head);
    head = DeleteOnData(head, 3);
    head = DeleteOnData(head, 8);
    head = DeleteOnData(head, 1);
    head = DeleteOnData(head, 9);
    // head = DeleteOnData(head, 0);
    printf("\n");
    TraverseUsingHead(head);

    // Free the memory
    Node *current = head;

    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}