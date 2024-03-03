#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

// Global variables
char stack[SIZE], infix[SIZE];
char symb, x;
int top = -1;

// Push function definition
void push(char item)
{
    if (top >= SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

// Pop function definition
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    else
        return stack[top--];
}

// Operator precedence function definition
int priority(char symbol)
{
    if (symbol == '(')
        return 0;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else if (symbol == '*' || symbol == '/' || symbol == '%')
        return 2;
    else if (symbol == '^' || symbol == '$')
        return 3;
    else
        return 0;
}

// Infix to postfix conversion function definition
void infix_postfix(char infix[])
{
    int i;
    printf("Postfix Expression  :");
    for (i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i];
        if (isalnum(symb))
            printf("%c ", symb); /* place the character in postfix expression */
        else if (symb == '(')
            push(symb);
        else if (symb == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(symb))
                printf("%c ", pop());
            push(symb);
        }
    }
}

// Main function
int main()
{
    printf("ASSUMPTION: The Infix Expression contains single letter variables and single digit constants only.\n");
    printf("\nEnter the Infix Expression : ");
    scanf("%s", infix);
    printf("\n");
    push('(');               // push '(' onto stack
    strcat(infix, ")");       // append ')' to infix expression where ")" acts as sentinel
    infix_postfix(infix);
    return 0;
}
