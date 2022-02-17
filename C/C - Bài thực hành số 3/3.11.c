// Kiểm tra các chữ số của n có sắp xếp theo thứ tự tăng dần hay không
// Find out the first digit of n
// Count the number of appearences of the first digit
#include <stdio.h>
#include <stdbool.h>

int input_n() {
	int n = 0;
	while (n <= 0) {
		printf("import n > 0: ");
		scanf("%d", &n);
	}
	return n;
}

bool check_the_sort(int n) {
	int a, b;
	a = n % 10;
	n /= 10;
	while (n > 0) {
		b = n % 10;
		n /= 10;
		if (b >= a) {
			return false;
		}
		a = b;
	}
	return true;
}

int firstDigit(int n) {
	int digit = 0;
	while (n > 0) {
		digit = n % 10;
		n /= 10;
	}
	return digit;
}

int count_the_number_of_the_FirstDigit(int n) {
	int first = firstDigit(n);
	int count = 0;
	int Digit;
	while (n > 0) {
		Digit = n % 10;
		n /= 10;
		if (Digit == first) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;

	n = input_n();

	if (check_the_sort(n)) {
		printf("True\n");
	}
	else {
		printf("False\n");
	}

	printf("The first digit of n: %d\n", firstDigit(n));

	printf("the number of appearences of the first digit: %d\n", count_the_number_of_the_FirstDigit(n));

	return 0;
}