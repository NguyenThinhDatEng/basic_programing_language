// Use recursive
#include<stdio.h>

int theSum_of_theDigits_of_n(int n)
{
	if (n < 10) return n;
	else
		return n % 10 + theSum_of_theDigits_of_n(n / 10);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", theSum_of_theDigits_of_n(n));
    return 0;
}