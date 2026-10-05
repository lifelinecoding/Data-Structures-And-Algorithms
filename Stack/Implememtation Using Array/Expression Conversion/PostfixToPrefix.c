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

void PostfixToPrefix(char *postfix, char *prefix){
    Stack st;
    initialize(&st);
    char ch;
    char op1[MAX], op2[MAX], temp[MAX];
    int i = 0;

    // Scan from Left to Right
    while (postfix[i] != '\0'){
        ch = postfix[i];

        // If operand, push as a single-character string
        if(isalnum(ch)){
            char operand[2] = {ch, '\0'};
            push(&st, operand);
        }
        // If operator, pop two operands and construct prefix sub-expression
        else if(isOperator(ch)){
            pop(&st, op1); 
            pop(&st, op2);

            // Combine into: op2 operator op1
            snprintf(temp, sizeof(temp), "%c%s%s", ch, op2, op1);
            push(&st, temp);
        }
        i++;
    }

    // The final result string remains at top of stack
    pop(&st, prefix);    
}

int main(){
    char postfix[MAX] = "34*92-+";
    char prefix[MAX];

    PostfixToPrefix(postfix, prefix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}