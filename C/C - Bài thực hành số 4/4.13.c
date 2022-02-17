// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Nhập thêm giá trị k sao cho 0 <= k < n. Xóa phần tử tại vị trí k khỏi mảng. 
// In mảng kết quả sau khi xóa ra màn hình.
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


int input_k(int n) {
	int k;
	do
	{
		printf("import k (0 <= k < n): ");
		scanf("%d", &k);
	} while (k < 0 || k >= n);
	return k;
}

void delete_the_element_at_position_k(int* arr, int* n, int k) {
	for (int i = k; i < *n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	*n -= 1;
}

void display(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%10d", arr[i]);
	}
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	int k = input_k(n);
	delete_the_element_at_position_k(arr, &n, k);
	display(arr, n);
	return 0;
}
