// Phân 1 số tích thành thừa số nguyên tố
#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%u", &n);

	if (n < 2) {
		printf("Import n > 1: ");
	}
	else {
		unsigned int i = 2;
		printf("%u = ", n);
		while (n > 1) {
			if (n % i == 0) {
				printf("%u", i);
				if (n != i) {
					printf("x");
				}
				n /= i;
			}
			else {
				i++;
			}
		}
	}

	return 0;
}