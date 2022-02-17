// Nhập vào hai số dương m, n sau đó in ra hình chữ nhật rỗng bằng các dấu x.
#include<stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("x\t", j);
        }
        puts("\n");
    }
    return 0;
}