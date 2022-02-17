#include <stdio.h>

void input_arr_and_n(int* arr, int* n) {
	do
	{
		printf("import n > 0: ");
		scanf("%d", n);
	} while (*n < 1);
	for (int i = 0; i < *n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}


void import_a_b(int* a, int* b) {
	while (1) 
	{
		printf("import a < b: ");
		scanf("%d%d", a, b);
		if (*a < *b) 
		{
			break;
		}
	}
}

int sum(int* arr, int n, int a, int b) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= a && arr[i] <= b) {
			sum += arr[i];
		}
	}
	return sum;
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);

	int a, b;
	import_a_b(&a, &b);
	printf("sum [%d, %d] = %d", a, b, sum(arr, n, a, b));

	return 0;
}