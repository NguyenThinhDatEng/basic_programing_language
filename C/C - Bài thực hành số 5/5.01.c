// Hãy chuyển một số ở hệ 10 thành số ở hệ cơ số b bất kì (1< b ≤ 16).
#include<stdio.h>
#include<string.h>
const char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	short surplus;
	char str[100];
	short i = 0;
	if (n == 0) printf("0");
	for (i = 0; n > 0; i++)
	{
		surplus = n % b;
		n /= b;
		str[i] = digit[surplus];
	}
	str[i] = '\0';
	strrev(str);
	printf("result: ");
	puts(str);
	return 0;
}