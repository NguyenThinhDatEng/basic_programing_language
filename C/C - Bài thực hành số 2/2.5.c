// Bai tap 2.5: tinh tong 1! + 2! + ... + n!
#include <stdio.h>

int main() {
	unsigned int n;
	unsigned long long sum = 0;
	unsigned long long gt = 1;
	scanf("%u", &n);
	int i;
	for (int i = 1; i <= n; i++) {
		gt *= i; // gt: i!
		sum += gt; // sum = sum + i!
	}
	printf("SUM = %llu\n", sum);

	return 0;
}