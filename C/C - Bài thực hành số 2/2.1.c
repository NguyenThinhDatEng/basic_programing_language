#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 0)
    {
        if (n != 1) printf("the number is less than %d and not divisible by 2\n", n);
        for (int i = 1; i < n; i += 2)
        {
            printf("%d ", i);
        }
        printf("\nthe number is less than %d and divisible by 2\n", n);
        for (int i = 0; i < n; i += 2)
        {
            printf("%d ", i);
        }
    }
    return 0;
}