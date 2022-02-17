// Hãy nhập vào hai số dương m, n sau đó in ra màn hình một hình chữ nhật m hàng, mỗi hàng liệt kê các giá trị từ 1 đến n
#include<stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", j);
        }
        puts("");
    }
    return 0;
}