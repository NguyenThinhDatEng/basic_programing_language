#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int a, b;
	printf("Import a < b, a > 0: ");
	scanf("%d%d", &a, &b);

	if (a > 0 && b > 0) {
		for (int i = a; i <= b; i++) {
			if (checkPrime(i)) {
				printf("%10d", i);
			}
		}
	}
	else {
		printf("Import a and b are positive numbers or review condition a < b");
	}

	return 0;
}