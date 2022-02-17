//Cho mảng số nguyên gồm n phần tử và n - 1 phần tử tùy ý nhập từ bàn phím hoặc file. Sắp xếp n - 1 phần tử của mảng này theo thứ tự tăng dần. 
// Sau đó nhập một số nguyên x tùy ý. Chèn x vào mảng sao cho vẫn giữ được tính chất sắp xếp của mảng.
#include <stdio.h>

void input_arr_and_n(int* arr, int* n) {
	do
	{
		printf("import n > 0: ");
		scanf("%d", n);
	} while (*n < 1);
	for (int i = 0; i < *n - 1; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}


void sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int t = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = t;
			}
		}
	}
}

int seek_the_index_to_insert(int* arr, int n, int x) {
	if (x < arr[0]) {
		return 0;
	}
	if (x > arr[n - 1]) {
		return n;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] >= x) {
			return i;
		}
	}
}

void insert(int* arr, int n, int index, int x) {
	for (int i = n - 1; i > index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = x;
}

void display(int* arr, int n) {
	for (int i = 0; i < n; i++) 
	{
		printf("%-10d", arr[i]);
	}
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	sort(arr, n - 1);

	int x;
	printf("Import x: ");
	scanf("%d", &x);

	int index = seek_the_index_to_insert(arr, n - 1, x);
	insert(arr, n, index, x);
	display(arr, n);
	return 0;
}