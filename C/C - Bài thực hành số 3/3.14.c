/*
Liệt kê các số có 8 chữ số thỏa mãn đồng thời các điều kiện sau:
a) Là số nguyên tố
b) Chỉ chứa chữ số nguyên tố
c) Tổng các chữ số của nó cũng là số nguyên tố
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

bool Sum_the_digits_of_prime(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (checkPrime(sum)) {
		return true;
	}
	return false;
}

bool check_the_digits_are_primes(int n) {
	int digit;
	if (n / 10000000 == (4 && 6)) return false;
	while (n > 1) {
		digit = n % 10;
		n /= 10;
		if (!checkPrime(digit)) {
			return false;
		}
	}
	return true;
}

int main() {
	int i;
	for (i = 22222223; i <= 77777777; i += 2)
	{
		if (check_the_digits_are_primes(i) && Sum_the_digits_of_prime(i) && checkPrime(i))
		{
			printf("%10d", i);
		}
	}
	return 0;
}

