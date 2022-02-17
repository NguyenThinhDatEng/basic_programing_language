#include<stdio.h>

int main() {
	unsigned int n;
	scanf("%u", &n);
	unsigned int sum = 0;
	while (n > 0)
	{
		sum += n--;
	}
	printf("SUM = %u", sum);
	return 0;
}