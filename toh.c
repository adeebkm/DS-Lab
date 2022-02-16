#include <stdio.h>

void toh(int n, char source, char temp, char destination)
{
    if (n == 1)
        printf("move disk %d from %c to %c ", n, source, destination);

    else
    {
        toh(n - 1, source, destination, temp);
        printf("move disk %d from %c to %c ", n, source, destination);
        toh(n - 1, source, temp, destination);
    }
}

void main()
{
    int n;
    printf("enter no of disks\n");
    scanf("%d", &n);
    printf("the sequence of steps are \n");
    toh(n, 'A', 'B', 'C');
}