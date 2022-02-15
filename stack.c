#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

void options()
{
    printf("\n1)push");
    printf("\n2)pop");
    printf("\n3)display");
    printf("\n4)exit");
}

void push(int element)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow");
        return;
    }
    else
    {
        stack[++top] = element;
        return;
    }
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack empty");
    }
    else
    {
        printf("Stack:");
        int i = 0;
        while (i <= top)
        {
            printf("%d ", stack[i]);
            i++;
        }
        printf("\n");
    }
}

int main()
{
    int element, element_deleted, choice;
    options();

    while (1)
    {
        printf("\nenter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER ELEMENT TO PUSH");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            element_deleted = pop();
            if (element_deleted == 0)
            {
                printf("stack underflow");
            }
            else
                printf("ELEMENT POPPED IS %d", element_deleted);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("wrong choice");
        }
    }
}