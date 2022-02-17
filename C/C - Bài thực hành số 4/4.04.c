// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Nhập thêm giá trị nguyên x và đếm số lần xuất hiện của x trong mảng.
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


int count_advent_of_x(int* arr, int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	int x;

	printf("import interge x: ");
	scanf("%d", &x);

	printf("the number of occurrences: %d", count_advent_of_x(arr, n, x));

	return 0;
}