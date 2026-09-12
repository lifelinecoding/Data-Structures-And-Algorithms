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

//Funtion to reverse a singly linked list.
Node* Reverse(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* Next = NULL;

    if(current == NULL){
        printf("No node exist in linked list.\n");
        return head;
    }

    while(current != NULL){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }

    return prev;
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
    // Node* empty = NULL;

    Node *head = (Node *)malloc(sizeof(Node));
    Node *first = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));
    Node *sixth = (Node *)malloc(sizeof(Node));
    Node *seventh = (Node *)malloc(sizeof(Node));
    Node *eighth = (Node *)malloc(sizeof(Node));
    Node *ninth = (Node *)malloc(sizeof(Node));
    Node *tenth = (Node *)malloc(sizeof(Node));


    // Assigning values to node
    head->data = 1;
    first->data = 2;
    second->data = 3;
    third->data = 4;
    fourth->data = 5;
    fifth->data = 6;
    sixth->data = 7;
    seventh->data = 8;
    eighth->data = 9;
    ninth->data = 10;
    tenth->data = 11;

    // Connection
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = NULL;

    Traverse(head);
    printf("\n");
    // empty = Reverse(empty);
    head = Reverse(head);
    Traverse(head);

    // Free Memory location
    free(head);
    free(first);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(sixth);
    free(seventh);
    free(eighth);
    free(ninth);
    free(tenth);

    return 0;
}