#include<stdio.h>
const float pi = 3.14;

int main()
{
    float r;
    scanf("%f", &r);
    printf("circumference is %f", 2 * pi * r);
    printf("\ncircle area is %f", pi * r * r);
    return 0;
}