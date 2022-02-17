// Hiển thị các ước nguyên tố duy nhất 1 lần
#include <stdio.h>

int main() {
	unsigned int n;
	printf("Import number n > 1: ");
	scanf("%u", &n);

	if (n < 2) {
		printf("Import n > 1");
	}
	else {
		unsigned int i = 2;
		int mark = 0;
		while (n > 1) {
			if (n % i == 0) {
				if(mark != i) printf("%u ", i);
				n /= i;
				mark = i;
			}
			else {
				i++;
			}
		}
	}

	return 0;
}