#include <stdio.h>
#include <conio.h>
#include <math.h>

int gcd(int x1, int x2)
{
    int rem = x1 % x2;
    if (rem == 0)
    {
        return x2;
    }
    else
        gcd(x2, rem);
}

void main()
{
    int x1, x2;
    printf("enter x1 :");
    scanf("%d", &x1);
    printf("enter x2 :");
    scanf("%d", &x2);
    if (x1 == 0 && x2 == 0)
    {
        printf("gcd not derfined\n");
    }
    else if (x1 == 0)
    {
        printf("gcd is %d\n", x2);
    }
    else if (x2 == 0)
    {
        printf("gcd is %d\n", x1);
    }
    else
    {
        int val = gcd(x1, x2);
        printf("the gcd of %d and %d is %d", x1, x2, val);
    }
}
