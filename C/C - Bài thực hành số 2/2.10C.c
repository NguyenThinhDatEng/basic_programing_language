// Phân tích một số ra thừa số nguyên tố dạng số mũ
#include <stdio.h>

int main() {
	unsigned int n;
	printf("Import number n > 1: ");
	scanf("%u", &n);

	if (n < 2) {
		printf("Import n > 1");
	}
	else {
		unsigned int i = 2;
		int count = 0;
		while (n > 1)
		{
			if (n % i == 0) 
			{
				n /= i;
				count++;
				if (n == 1) printf("%d^%d", i, count);
			}
			else {
				if (count) printf("%d^%d x ", i, count);
				i++;
				count = 0;
			}
		}
	}
	return 0;
}