// Nhập vào số dương n và một mảng các phần tử từ arr[0] đến arr[n - 1]. Hãy tìm giá trị lớn nhất và nhỏ nhất trong mảng trên.
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

void find_min_max(int* arr, int n, int* min, int* max) {
	for (int i = 1; i < n; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
	if (*max == *min) printf("have not both min and max");
	else
		printf("\nMIN = %d\nMAX = %d\n", *min, *max);
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	int min = arr[0], max = arr[0];
	find_min_max(arr, n, &min, &max);
	return 0;
}
