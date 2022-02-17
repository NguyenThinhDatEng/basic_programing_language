// Tính số PI
#include<stdio.h>
#include<math.h>

int main()
{
    double a;
    double pi = 0;
    scanf("%lf", &a);
    for (int i = 0; a < 1.0f / (2 * i + 1); i++)
    {
        pi += pow(-1, i) * 1.0f / (2 * i + 1);
    }
    printf("%.8lf", pi * 4);
    return 0;
}