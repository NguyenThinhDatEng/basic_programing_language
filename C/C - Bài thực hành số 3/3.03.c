// Nhập số dương h sau đó in ra tam giác vuông góc trái dưới có chiều cao h bằng các dấu *
#include<stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    int j = 0;
    for (int i = 1; i <= h; i++)
    {
        j = i;
        while (j > 0)
        {
            printf(" * ");
            j--;
        }
        puts("");
    }
    return 0;
}