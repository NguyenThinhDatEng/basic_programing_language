// Tính và in ra tam giác Pascal
#include<stdio.h>

int factorial_of_n(int n)
{
    if (n <= 1) return 1;
    else
        return factorial_of_n(n - 1) * n;
}

int combination_C_k_n(int k, int n)
{
    int com = factorial_of_n(n) / (factorial_of_n(k) * factorial_of_n(n - k));
    return com;
}

int main()
{
    int i, j;
    int k, n;
    printf("Import n >= 0: \n");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        k = 0;
        for (j = 0; j < n - i; j++)
        {
            printf("     ");
        }
        for (j = 1; j <= 2 * i + 1; j++)
        {
            if (j % 2)
            {
                printf("  %d  ", combination_C_k_n(k, i));
                k++;
            }
            else
                printf("     ");
        }
        puts("");
    }
    return 0;
}