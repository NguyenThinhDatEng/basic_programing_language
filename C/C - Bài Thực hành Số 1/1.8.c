#include<stdio.h>

int main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    printf("We have a linear equation: %fx + %f = 0\n", a, b);
    if (a)
    {
        printf("The equation has a unique root is x = %f\n", -b / a);
    }
    else
        if (b) printf("the equation has no solution\n");
        else
            printf("the equation has countless solution\n");
    return 0;
}