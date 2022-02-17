// Viết hàm kiểm tra số thuận nghịch sử dụng xâu kí tự. Áp dụng để hiển thị các số thuận nghịch có 9 chữ số.
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool audit_reversible_number(unsigned int n)
{
	char str[20];
	ltoa(n, str, 10);
	char str1[20];
	strcpy(str1, str);
	strrev(str);
	return strcmp(str, str1) == 0;
}

int main()
{
	for (unsigned int i = pow(10, 8); i <= pow(10, 9) - 1; i++)
	{
		if (audit_reversible_number(i)) printf("%10u", i);
	}
	return 0;
}