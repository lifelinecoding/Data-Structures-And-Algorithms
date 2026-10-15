#include<stdio.h>
#include<windows.h>
#include<string.h>
#define Capacity 100

// Stack definition
typedef struct Stack{
    char items[100];
    int top;
} Stack;

// Function to initialize empty stack.
void initialize(Stack *st){
    st->top = -1;
}

// Function to check stack is full
int isFull(Stack *st){
    if(st->top == Capacity - 1){
        return 1;
    }
    return 0;
}

// Function to check if stack is empty
int isEmpty(Stack *st){
    if(st->top < 0){
        return 1;
    }
    return 0;
}

// Function to push an element into stack.
void push(Stack *st, char newItem){
    if(!isFull(st)){
        st->items[++(st->top)] = newItem;
    }
}

// Function to pop top element of stack.
char pop(Stack *st){
    if(!isEmpty(st)){
        return st->items[(st->top)--];
    }
    return '\0';
}

// Function to match the corresponding brackets.
int Matching(char opening, char closing){
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

// Function to match the brackets.
int ParanthesisMatching(char expression[], Stack *st){
    int length = strlen(expression);
    char ch;
    for(int i = 0; expression[i] != '\0'; i++){
        ch = expression[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(st, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(!Matching(pop(st), ch)) return 0;
        }
        else continue;
    }

    return isEmpty(st);
}

int main(){
    char Expression[] = "[A+B*(C-D)+{E/F-G*H}]";
    Stack st;
    initialize(&st);
    if(ParanthesisMatching(Expression, &st )){
        printf("Expression is valid!\n");
    }
    else{
        printf("Invalid expression!\n");
    }
return 0;
}