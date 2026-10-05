#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

// Node Definition.
typedef struct Node{
    int data;
    struct Node* next;
} Node;

// Stack Definition.
typedef struct Stack{
    Node* top;
} Stack;


int isEmpty(Stack * st){
    if(st->top == NULL){
        return 1;
    }
    return 0;
}

int push(Stack* st, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation for new node has been failed! Stack Overflow.");
        return 0;
    }

    if(st->top == NULL){
        newNode->data = item;
        newNode->next = NULL;
        st->top = newNode;
    }
    else{
        newNode->data = item;
        newNode->next = st->top;
        st->top = newNode;
    }  
}

int pop(Stack *st){
    if(!isEmpty(st)){
        Node *temp = st->top;
        st->top = temp->next;
        int value = temp->data;
        free(temp);
        return value;
    }
}

int peek(Stack *st){
    if(!isEmpty(st)){
        return st->top->data;
    }
}

void Display(Stack *st){
    Node *current = st->top;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    Stack st;
    st.top = NULL;

    push(&st, 5 );
    push(&st, 6 );
    push(&st, 8 );
    push(&st, 1 );
    push(&st, 4 );
    push(&st, 3 );
    push(&st, 2 );

    printf("%d ", pop(&st));
    printf("%d ", pop(&st));
    printf("%d \n", pop(&st));

    printf("%d \n", peek(&st));
    Display(&st);
    
return 0;
}