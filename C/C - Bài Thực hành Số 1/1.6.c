#include<stdio.h>

int main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    printf("perimeter of a rectangle is %f", 2 * (a + b));
    printf("\nretangle area is %f", a * b);
    return 0;
}