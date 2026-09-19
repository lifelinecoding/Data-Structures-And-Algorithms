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

// Travere using head
void TraverseUsingHead(Node* head){
    Node* current = head;
    do{
        printf("%d ", current->data);
        current = current->next;
    }  while(current != head); 
}

// Traverse Using tail
void TraverseUsingTail(Node* tail){
    Node* current = tail;
    do{
        printf("%d ", current->data);
        current = current->prev;
    } while(current != tail);
}

int main()
{
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
    tail->next = head;

    // Previous node connection
    tail->prev = seventh;
    seventh->prev = sixth;
    sixth->prev = fifth;
    fifth->prev = fourth;
    fourth->prev = third;
    third->prev = second;
    second->prev = first;
    first->prev = head;
    head->prev = tail;

    TraverseUsingHead(head);
    printf("\n");
    TraverseUsingTail(tail);

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