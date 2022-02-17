// Nhập vào ma trận cấp [m x n] với m, n > 0. Hãy tìm ma trận chuyển vị của ma trận này.
#include <stdio.h>
#define max 100
void import_arr_m_and_n(int *a[][max], int* m, int* n) 
{
	do {
		printf("import m, n > 0: ");
		scanf("%d%d", m, n);
	} while (*m <= 0 || *n <= 0);
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void display(int *a[][max], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void matrix_transposition(int *arr[][max], int m, int n) 
{
	for (int i = 1; i < n; i++) 
	{
		for (int j = 0; j < i; j++) {
			swap(&arr[i][j], &arr[j][i]);
		}
	}
}

int main() 
{
	int arr[max][max];
	int m, n;
	import_arr_m_and_n(arr, &m, &n);
	display(arr, m, n);
	printf("matrix transposition: \n");
	matrix_transposition(arr, m, n);
	display(arr, n, m);
	return 0;
}
