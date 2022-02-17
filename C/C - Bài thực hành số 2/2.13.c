// kiem tra so thuan nghich
#include <stdio.h>

int main() {
	long n;
	scanf("%ld", &n);
	if (n < 0) {
		printf("import n > 0!");
	}
	else {
		long reverse = 0;
		long m = n;
		while (m > 0) {
			reverse = reverse * 10 + m % 10;
			m /= 10;
		}

		if (reverse == n) {
			printf("True\n", n);
		}
		else {
			printf("False\n");
		}
	}
	return 0;
}