// Nhập số dương h sau đó in ra tam giác cân với chiều cao h
#include<stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j < h - i + 1; j++)
        {
            printf("   ");
        }
        for (int j = h - i + 1; j <= h + i - 1; j++)
        {
            printf(" * ");
        }
        puts("");
    }
    return 0;
}