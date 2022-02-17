#include<stdio.h>
#include<math.h>

int main()
{
    unsigned int m, n;
    scanf("%u%u", &m, &n);

    int count = 0;
    for (int i = sqrt(m); i <= sqrt(n); i++)
    {
        if (pow(i, 2) <= n && pow(i, 2) >= m)
        {
            printf("%u ", i * i);
            count++;
        }
    }
    printf("\n%d", count);
    return 0;
}