// Bai 2.7: liet ke cac uoc cua so nguyen duong n
#include <stdio.h>
#include<math.h>

int main() {
	unsigned long n;
	unsigned int count = 2;
	scanf("%lu", &n);

	printf("1 %d ", n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (i * i != n)
			{
				printf("%d %d ", i, n / i);
				count += 2;
			}
			else
			{
				printf("%d ", i);
				count++;
			}
		}
	}
	printf("\n%lu has %u divisors.\n", n, count);

	return 0;
}