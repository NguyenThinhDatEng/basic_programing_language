#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    printf("We have a quadratic equation: %.3fx^2 + %.3fx + %.3f = 0\n", a, b, c);
    if (a)
    {
        int denta;
        denta = b * b - 4 * a * c;
        if (denta < 0) printf("the equation has no solution");
        else
            if (denta > 0) printf("the equation has 2 distinct solutions\nx1 = %f\nx2 = %f", (-b + sqrt(denta)) / (2 * a), (-b - sqrt(denta)) / (2 * a));
            else
                printf("the equation has a double solution x = %f", -b / (2 * a));
    }
    else
        if (b)
        {
            printf("the equation has a unique root x = %f", - c / b);
        }
        else
            if (c) printf("the equation has no solution");
            else
                printf("the equation has countless solution");
    return 0;
}