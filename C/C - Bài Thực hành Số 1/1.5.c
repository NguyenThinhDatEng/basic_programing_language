#include<stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int max = a;
    if ((a = b) && (a == c) && (a == d))
    {
        printf("khong co so lon nhat");
    }
    else
    {
        if (max < b) max = b;
        if (max < c) max = c;
        if (max < d) max = d;
        printf("%d", max);
    }
    return 0;
}