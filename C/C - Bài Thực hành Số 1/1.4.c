#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    a >= b ? (a > b ? printf("%d is greater than %d", a, b) : printf("two numbers are equal")) : printf("%d is less than %d", a, b);
    return 0;
}