//Tìm ước chung lớn nhất, bội chung nhỏ nhất
#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	if (a >= 0 && b >= 0) {
		if (a == 0 && b == 0) {
			printf("Doesn't exist UCLN, BCNN\n");
		}
		else if (a == 0 || b == 0) {
			printf("Doesn't exist BCNN\nUCLN = %d", (a == 0) ? b : a);
		}
		else {
			int ab = a * b;
/*			cach 1:
			while(a != b) 
			{
				if(a > b) 
					a = a - b;
				else 
					b = b - a;
			}
*/
			// cach 2:
			while (a != 0) {
				int x = a;
				a = b % a;
				b = x;
			}

			printf("greatest common divisor is %d\n", b);
			printf("least common multiple is %d\n", ab / b);
		}
	}
	else {
		printf("import a, b > 0");
	}

	return 0;
}