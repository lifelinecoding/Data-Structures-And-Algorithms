#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

// Node definition
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

// Type definition
typedef struct Node Node;

// Function to delete a node at specified position in doublly linked list.

Node* DeleteOnPosition(Node* head, int position){
    Node* current = head;
    Node* Next = NULL;

    if(position <= 0){
        printf("Invalid Position.\n");
        return head;
    }

    if(current == NULL){
        printf("No node exist for deletion.\n");
        return head;
    }

    Next = current->next;
    if(position == 1){
        free(current);
        Next->prev = NULL;
        return Next;
    }


    for(int i = 1; i < position - 1 && current->next != NULL; i++){
        current = current->next;
        Next = current->next;
    }

    current->next = Next->next;
    if(Next->next != NULL){
        (Next->next)->prev = current;
    }
    free(Next);
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
    // Node* head = NULL;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* first = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));
    Node* fourth = (Node*)malloc(sizeof(Node));
    Node* fifth = (Node*)malloc(sizeof(Node));
    Node* sixth = (Node*)malloc(sizeof(Node));
    Node* seventh = (Node*)malloc(sizeof(Node));
    Node* tail = (Node*)malloc(sizeof(Node));

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
    head  = DeleteOnPosition(head, 3);
    head  = DeleteOnPosition(head, 1);
    head  = DeleteOnPosition(head, -2);
    printf("\n");
    TraverseUsingHead(head);

    // Free the memory
    free(head);
    free(first);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(sixth);
    free(seventh);
    free(tail);

return 0;
}