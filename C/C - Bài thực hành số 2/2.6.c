// Bai 2.6: tinh tong cac so tu nhien khong lon hon n va chia het cho 7
#include <stdio.h>

int main() {
	unsigned int n;
	unsigned long long sum = 0;
	scanf("%u", &n);
	for (long i = 7; i <= n; i += 7) {
		sum += i;
	}
	printf("SUM = %llu", sum);

	return 0;
}