#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    n % 2 ? printf("%d is odd number", n) : printf("%d is even number");
    n > 0 ? printf("\n%d is positive number", n) : printf("\n%d is negative number", n);
    return 0;
}