#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%u", &n);
	float sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += 1.0f / i;
		// ép kiểu ngầm định
	}
	printf("SUM = %.5f", sum);

	return 0;
}
