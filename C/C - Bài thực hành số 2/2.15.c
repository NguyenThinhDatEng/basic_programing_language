// Hãy viết chương trình tính tổng các chữ số của một số nguyên bất kỳ.
//Ví dụ : số 8545604 có tổng các chữ số là : 8 + 5 + 4 + 5 + 6 + 0 + 4 = 32
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 0) n *= -1;

	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	printf("the sum of the digits of n = %d\n", sum);
	return 0;
}