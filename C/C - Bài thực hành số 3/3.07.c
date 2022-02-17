// Số thuận nghịch có 8 chữ số chia hết cho k
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

int main() {
	int i, k;
	printf("import k > 0: ");
	scanf("%d", &k);

	for (i = 10000000; i <= 99999999; i++) {
		if (i % k == 0 && reverse(i)) {
			printf("%10d", i);
		}
	}

	return 0;
}
