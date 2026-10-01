// Online C compiler to run C program online
#include <stdio.h>
#include <ctype.h>
#define MAX 100

struct Stack
{
    int top;
    char items[MAX];
};

typedef struct Stack Stack;

// Function to initialize an empty stack
void initialize(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(Stack *s)
{
    if (s->top < 0)
    {
        return 1;
    }

    return 0;
}

char peek(Stack *s)
{
    return s->items[s->top];
}

void push(Stack *s, int item)
{
    if (!isFull(s))
    {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        char value = (s->items[(s->top)--]);
        return value;
    }

    printf("Stack Underflow\n");
    return -1;
}

// Check if character is an operator
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to return operator precedence
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack st;
    initialize(&st);
    int i = 0, j = 0;
    char ch;

    // Scanning the expression from left to right.
    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '[' || ch == '{' || ch == '(')
        {
            push(&st, ch);
        }
        else if (ch == ']' || ch == '}' || ch == ')')
        {
            if (ch == ']')
            {
                while (!isEmpty(&st) && peek(&st) != '[')
                {
                    postfix[j++] = pop(&st);
                }
            }
            else if (ch == '}')
            {
                while (!isEmpty(&st) && peek(&st) != '{')
                {
                    postfix[j++] = pop(&st);
                }
            }
            else if (ch == ')')
            {
                while (!isEmpty(&st) && peek(&st) != '(')
                {
                    postfix[j++] = pop(&st);
                }
            }
            pop(&st);
        }

        else if (isOperator(ch))
        {
            while (!isEmpty(&st) && (precedence(peek(&st)) > precedence(ch) || precedence(peek(&st)) == precedence(ch) && ch != '^'))
            {
                postfix[j++] = pop(&st);
            }

            push(&st, ch);
        }

        i++;
    }

    // Poping all the remaining elements from the stack and adding them to postfix expression.
    while (st.top >= 0)
    {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
}

int main()
{
    // char infix[MAX] = "(A+B)*[C*{P*Q}/Y]";
    char infix[MAX] = "z+[(y*x)-(w/v+u)*t]*s";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("%s", postfix);

    return 0;
}