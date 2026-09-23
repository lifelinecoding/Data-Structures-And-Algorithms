#include <stdio.h>
#include <windows.h>
#define Capacity 5

struct Stack
{
    int arr[Capacity];
    int top;
};

typedef struct Stack Stack;

// Check Stack Underflow.

int isEmpty(Stack* st)
{
    if (st->top < 0)
    {
        printf("Stack Underflow!");
        return 1;
    }

    return 0;
}

// Check Stack Overflow

int isFull(Stack *st)
{
    if (st->top == Capacity - 1)
    {
        printf("Stack Overflow!");
        return 1;
    }
    return 0;
}

// Push an element into the Stack.
int Push(Stack* st, int newItem)
{
    if (!isFull(st))
    {
        st->arr[++(st->top)] = newItem;
        return 1;
    }
    return 0;
}

// Pop an element from stack.
int Pop(Stack* st){
    if(!isEmpty(st)){
        return st->arr[(st->top)--];
    }
return -1;
}

// Check the top most element of the stack
int Peek(Stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top];
    }
}

void PrintStackElements(Stack* st){
    for(int i = 0; i <= st->top; i++){
        printf("%d ", st->arr[i]);
    }
}

int main()
{
    Stack st;
    st.top = -1;
    Push(&st, 2);
    Push(&st, 6);
    Push(&st, 4);
    Push(&st, 1);
    Push(&st, 9);
    // Push(&st, 2);

    printf("%d \n", Pop(&st));
    printf("%d \n", Pop(&st));
    printf("%d \n", Pop(&st));
    printf("%d \n", Pop(&st));
    printf("%d \n", Pop(&st));
    printf("%d \n", Pop(&st));

    // PrintStackElements(&st);
    return 0;
}