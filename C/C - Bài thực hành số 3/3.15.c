/*
Liệt kê các số có 8 chữ số thỏa mãn đồng thời các điều kiện sau:
a) Là số thuận nghịch
b) Không chứa chữ số 6
c) Tổng các chữ số là số nguyên tố
*/
#include <stdio.h>
#include <stdbool.h>

bool reverse(int n) {
	int m = 0;
	int save = n;
	while (n > 0) {
		m = m * 10 + n % 10;
		n /= 10;
	}
	return save == m;
}

bool not_include_the_digit_6(int n) {
	int digit;
	while (n > 0) {
		 digit = n % 10;
		n /= 10;
		if (digit == 6) {
			return false;
		}
	}
	return true;
}

bool sum_the_digits_is_divisiable_by_6(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum % 6 == 0;
}

int main() {
	for (int i = 10000000; i <= 99999998; i += 2) {
		if (not_include_the_digit_6(i) && sum_the_digits_is_divisiable_by_6(i) && reverse(i)) {
			printf("%10d", i);
		}
	}
	return 0;
}
