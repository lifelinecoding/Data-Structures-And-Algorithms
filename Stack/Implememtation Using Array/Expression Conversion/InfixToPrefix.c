// Online C compiler to run C program online
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    Stack st;
    initialize(&st);
    int length = strlen(infix);
    int j = length - 1;
    prefix[length] = '\0';
    char ch;

    // Scan the expression from right to left.
    for (int i = length - 1; i >= 0; i--)
    {
        ch = infix[i];
        if (isalnum(ch))
        {
            prefix[j--] = ch;
        }
        else if (ch == ']' || ch == '}' || ch == ')')
        {
            push(&st, ch);
        }
        else if (ch == '[' || ch == '{' || ch == '(')
        {
            if (ch == '[')
            {
                while (!isEmpty(&st) && peek(&st) != ']')
                {
                    prefix[j--] = pop(&st);
                }
            }
            else if (ch == '{')
            {
                while (!isEmpty(&st) && peek(&st) != '}')
                {
                    prefix[j--] = pop(&st);
                }
            }
            else if (ch == '(')
            {
                while (!isEmpty(&st) && peek(&st) != ')')
                {
                    prefix[j--] = pop(&st);
                }
            }

            pop(&st);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&st) && (
                (ch == '^' && precedence(ch) <= precedence(peek(&st))) ||
                (ch != '^' && precedence(ch) < precedence(peek(&st)))
            ))
            {
                prefix[j--] = pop(&st);
            }
            push(&st, ch);
        }
    }

    // Poping all the remaining elements from the stack and adding them to prefix expression.
    while (!isEmpty(&st))
    {
        prefix[j--] = pop(&st);
    }

    // Trim the string because brackets has been removed.
    int start = j + 1;
    int k = 0;
    while (start <= length)
    {
        prefix[k++] = prefix[start++];
    }
}

int main()
{
    char infix[MAX] = "(A+B)*[C*{P*Q}/Y]";
    // char infix[MAX] = "(A+B)-(C*D)";
    char prefix[MAX];

    infixToPrefix(infix, prefix);

    printf("%s", prefix);
    return 0;
}