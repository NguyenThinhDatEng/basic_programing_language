#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%u", &n);
	unsigned int s = 0, s1 = 0, s2 = 0;

	for (int i = 1; i <= n; i++) {
		s += i;
		if (i % 2 == 0) {
			s2 += i;
		}
		else {
			s1 += i;
		}
	}

	printf("Sum S = %u\n", s);
	printf("Even Sum S2 = %u\n", s2);
	printf("ODD Sum S1 = %u\n", s1);
	return 0;
}