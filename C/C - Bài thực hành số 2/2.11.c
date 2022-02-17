// Bai 2.11: Liet ke n so nguyen to dau tien
#include <stdio.h>
#include <math.h>
#include<stdbool.h>

bool checkPrime(int n)
{
	int mark = 1;
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			mark = 0;
			break;
		}
	}
	if (mark) return true;
	else
		return false;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 0) {
		printf("Let's import even number n!: \n");
	}
	else {
		for (int i = 2; n > 0; i++)
			if (checkPrime(i))
			{
				printf("%d ", i);
				n--;
			}
	}
	return 0;
}