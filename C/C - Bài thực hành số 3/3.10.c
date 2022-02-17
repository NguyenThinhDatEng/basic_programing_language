// Write 3 functions: Đếm và tính trung bình cộng các chữ số của một số
#include <stdio.h>

int input_n() {
	int n = 0;
	while (n <= 0) {
		printf("import n > 0: ");
		scanf("%d", &n);
	}
	return n;
}

int count_the_digits_of_n(int n) {
	int count = 0;
	while (n > 0) {
		count++;
		n /= 10;
	}
	return count;
}

int count_the_odd_digits(int n) {
	int count = 0;
	int digit;
	while (n > 0) {
		digit = n % 10;
		if (digit % 2 != 0) {
			count++;
		}
		n /= 10;
	}
	return count;
}

float average(int n) {
	float avarage = 0;
	int count = count_the_digits_of_n(n);
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	avarage = (float)sum / count;
	return avarage;
}

int main() {
	int n = input_n;
	printf("number of digits of n: %d\n", count_the_digits_of_n(n));
	printf("number of odd digits of n: %d\n", count_the_odd_digits(n));
	printf("average of digits of n: %0.2f", average(n));
	return 0;
}