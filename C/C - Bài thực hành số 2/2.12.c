#include <stdio.h>
#include <math.h>

int main() {
	int n;
	unsigned long long f0 = 1;
	unsigned long long f1 = 1;
	unsigned long long fn;
	scanf("%d", &n);

	if (n < 0) {
		printf("Import n >= 0\n");
	}
	else {
		if (n < 3) printf("f%d = 1\n", n - 1);
		else
		{
			for (int i = 3; i <= n; i++) {
				fn = f0 + f1;
				f0 = f1;
				f1 = fn;
			}
			printf("f%d = %lld.\n", n - 1, fn);
		}
	}

	return 0;
}