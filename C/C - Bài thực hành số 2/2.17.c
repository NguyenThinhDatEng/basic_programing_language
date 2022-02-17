//Nhập 2 số tự nhiên m, n rồi kiểm tra xem chúng có nguyên tố cùng nhau không(Hai số nguyên tố cùng nhau là 2 số có USCLN là 1).
#include <stdio.h>

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	if (m > 0 && n > 0) {
		while (m != n) {
			if (m > n) {
				m = m - n;
			}
			else {
				n = n - m;
			}
		}

		if (m == 1) {
			printf("True");
		}
		else {
			printf("False");
		}
	}
	else {
		printf("Import m, n > 0.");
	}
	return 0;
}