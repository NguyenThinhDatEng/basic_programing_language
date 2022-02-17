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


void sorted_in_ascending_order(int* arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

void sorted_in_descending_order(int* arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (arr[j] > arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

void Display(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

int main() {
	int n = 0;
	int arr[100];

	input_arr_and_n(arr, &n);
	printf("\nBefore arranging: \n");
	Display(arr, n);

	sorted_in_ascending_order(arr, n);
	printf("\nAfter arranging ascending: \n");
	Display(arr, n);

	sorted_in_descending_order(arr, n);
	printf("\nAfter arranging descending: \n");
	Display(arr, n);

	return 0;
}