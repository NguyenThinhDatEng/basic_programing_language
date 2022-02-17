// Bai 2.9: Kiem tra so nguyen to
#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 2) {
		printf("%d is not a prime\n", n);
	}
	else {
		int mark = 1;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				mark = 0;
				break;
			}
		}
		if (mark) {
			printf("%d is a prime\n", n);
		}
		else {
			printf("%d isn't a prime\n", n);
		}

	}
	return 0;
}