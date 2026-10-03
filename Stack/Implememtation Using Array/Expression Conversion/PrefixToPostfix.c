#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure holding strings for sub-expressions
typedef struct Stack{
    char items[MAX][MAX];
    int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    if (s->top < 0){
        return 1;
    }
    return 0;
}

int isFull(Stack *s){
    if (s->top == MAX - 1){
        return 1;
    }
    return 0;
}

void push(Stack *s, char *newExpression){
    if (!isFull(s)){
        strcpy(s->items[++(s->top)], newExpression);
    }
}

void pop(Stack *s, char *target){
    if (!isEmpty(s)){
        strcpy(target, s->items[(s->top)--]);
    }
}

int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

void PrefixToPostfix(char *prefix, char *postfix){
    Stack st;
    initialize(&st);

    int length = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];

    // Scan from Right to Left
    for (int i = length - 1; i >= 0; i--){
        char ch = prefix[i];

        // If operand, push as a single-character string
        if (isalnum(ch)){
            char operand[2] = {ch, '\0'};
            push(&st, operand);
        }
        // If operator, pop two operands and construct infix sub-expression
        else if (isOperator(ch)){
            pop(&st, op1); // First popped = Left operand
            pop(&st, op2); // Second popped = Right operand

            // Combine into: op1 operator op2
            snprintf(temp, sizeof(temp), "%s%s%c", op1, op2, ch);

            push(&st, temp);
        }
    }

    // The final result string remains at top of stack
    pop(&st, postfix);
}

int main(){
    char prefix[MAX] = "+*34-87";
    char postfix[MAX];

    PrefixToPostfix(prefix, postfix);

    printf("Prefix Expression: %s\n", prefix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}