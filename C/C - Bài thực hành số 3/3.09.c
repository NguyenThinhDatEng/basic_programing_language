// Write 3 function: nhập n, tổng chữ số và phân tích thừa số nguyên tố
#include <stdio.h>

int input_n() {
	int n = 0;
	while (n <= 0) {
		printf("Import n > 0: ");
		scanf("%d", &n);
	}
	return n;
}

int sum_of_digits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void analysis(int n) {
	int i = 2;
	printf("\ndissociate n to prime factor: ");
	while (i <= n) {
		if (n % i == 0) {
			printf("%d", i);
			n /= i;
			if (n != 1) printf(" x ");
		}
		else {
			i++;
		}
	}
}

int main() {
	int n;
	n = input_n();
	int sum = sum_of_digits(n);
	printf("Sum of the digits of n = %d", sum);
	analysis(n);

	return 0;
}
