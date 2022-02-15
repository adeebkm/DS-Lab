#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 100

int top = -1;
double stack[SIZE];

void push(double item)
{
    stack[++top] = item;
}

double pop()
{
    return stack[top--];
}

double evaluate(double num1, double num2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    case '^': // ^ and $ are used for exponents
    case '$':
        return pow(num1, num2); // function in math.c
    }
}

int isDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}
void main()
{
    char postfix[SIZE];
    printf("Enter a Valid Postfix Expression : ");
    scanf("%s", postfix);
    double num1, num2, res;
    char symbol;
    int i = 0;
    symbol = postfix[i];
    while (symbol != '\0')
    {
        if (isDigit(symbol))
        {
            // operand
            push(symbol - '0');
        }
        else
        {
            // operator
            num2 = pop();
            num1 = pop();
            res = evaluate(num1, num2, symbol);
            push(res);
        }
        i++;
        symbol = postfix[i];
    }
    res = pop();
    printf("Result : %lf", res);
}