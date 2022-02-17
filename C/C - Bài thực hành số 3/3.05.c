// Nhập số dương h sau đó in ra tam giác số đối xứng chiều cao h.
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
        int k = 0;
        for (int j = h - i + 1; j <= h + i - 1; j++)
        {
            j <= h ? printf(" %d ", ++k) : printf(" %d ", --k);
        }
        puts("");
    }
    return 0;
}