// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Hãy in ra các phần tử của nó sao cho mỗi phần tử chỉ xuất hiện duy nhất một lần.
#include <stdio.h>
#include <stdbool.h>

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


bool appeared(int* arr, int index, int x) {
	int i;
	for (i = 0; i < index; i++) {
		if (arr[i] == x) {
			return true;
		}
	}
	return false;
}

void display(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (!appeared(arr, i, arr[i])) {
			printf("%10d", arr[i]);
		}
	}
}


int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	display(arr, n);
	return 0;
}
//
