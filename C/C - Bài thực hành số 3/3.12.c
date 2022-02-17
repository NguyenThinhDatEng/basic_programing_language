// Lists positive integer divisors of n
// Count the number of divisors of n
// Lists prime divisors of n
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

void List_divisors_and_count(int n) {
	int count = 0;
	printf("the divisors of n are: ");
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) 
		{
			printf("%5d", i);
			if (i != n / i) {
				printf("%5d", n / i);
			}
			count += 2;
		}
	}
	printf("\nThe number of divisors = %d\n", count);
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

void list_prime_divisors(int n) {
	int i;
	printf("The prime divisors of n: ");
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (checkPrime(i)) {
				printf("%5d", i);
			}
			if (checkPrime(n / i) && i != (n / i)) {
				printf("%5d", n / i);
			}
		}
	}
}

int main() {
	int n = input_n();
	List_divisors_and_count(n);
	list_prime_divisors(n);

	return 0;
}
