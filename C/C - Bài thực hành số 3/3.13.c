/*
Liệt kê n số nguyên tố đầu tiên
Liệt kê n số fibonacci đầu tiên
Liệt kê n số chính phương đầu tiên
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int input_n() {
	int n = 0;
	while (n <= 0) {
		printf("import n > 0: ");
		scanf("%d", &n);
	}
	return n;
}

bool checkPrime(int n) {
	if (n < 2) {
		return false;
	}
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void list_the_first_n_primes(int n) {
	printf("the first %d primes are: \n", n);
	int i = 2;
	while (n > 0) {
		if (checkPrime(i)) {
			printf("%d ", i);
			n--;
		}
		i++;
	}
}

void list_the_first_n_fibonaci_number(int n) {
	printf("\nthe first %d fibonaci numbers are: \n", n);
	long long f1 = 1, f0 = 0, fn;
	int i;
	for (i = 0; i < n; i++) {
		if (i <= 1) {
			fn = i;
		}
		else {
			fn = f1 + f0;
			f0 = f1;
			f1 = fn;
		}
		printf("f%d = %lld\n", i, fn);
	}
}

void list_the_first_n_square_numbers(int n) {
	printf("\nthe first %d square numbers are: \n", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", i * i);
	}
}

int main() {
	int n = input_n();
	list_the_first_n_primes(n);
	list_the_first_n_fibonaci_number(n);
	list_the_first_n_square_numbers(n);
	return 0;
}
