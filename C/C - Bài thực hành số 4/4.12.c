// Cho mảng số nguyên gồm n phần tử trong đó có n - 1 phần tử tùy ý nhập từ bàn phím hoặc file. Hãy nhập thêm giá trị nguyên x và một số nguyên k sao cho 0 <= k < n. 
// Chèn x vào vị trí k của mảng.
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


int input_k(int n) {
	int k;
	do 
	{
		printf("import k (0 <= k < n): ");
		scanf("%d", &k);
	} while (k < 0 || k >= n);
	return k;
}

void insert(int* arr, int n, int k, int x) {
	for (int i = n - 1; i > k; i--) 
	{
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
}

void Display(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

int main() {
	int n;
	int arr[100];
	int k, x;

	input_arr_and_n(arr, &n);
	k = input_k(n);

	printf("import x: ");
	scanf("%d", &x);

	insert(arr, n, k, x);
	Display(arr, n);
	return 0;
}
