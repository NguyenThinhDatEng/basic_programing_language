// Tinh n!
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 0) {
		printf("Import n > 0!");
	}
	else {
		unsigned long long gt = 1;
		int i;
		for (i = n; i > 1; i--) {
			gt *= i;
		}
		printf("%d! = %lld", n, gt);
	}
	return 0;
}
