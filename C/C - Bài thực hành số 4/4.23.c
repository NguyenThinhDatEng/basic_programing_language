// Nhập vào hai ma trận A(m x n) và B(n x k). Tính tích hai ma trận.
#include<stdio.h>
#define number  100

void import_array(int arr[][number], int* m, int* n)
{
	do {
		printf("import m, n > 0: ");
		scanf("%d%d", m, n);
	} while (*m <= 0 || *n <= 0);
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			printf("arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void display_2_dimensional_arry(int a[][number], int m, int n) 
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void product_of_2_matrices(int a[][number], int b[][number], int c[][number], int m, int narr, int k)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < k; j++) 
		{
			for (int t = 0; t < narr; t++) 
			{
				c[i][j] += a[i][t] * b[t][j];
			}
		}
	}
}

int main() 
{ 
	int arr[number][number], b[number][number], c[number][number];
	int m, narr, nb, k;

	printf("Array arr: ");
	import_array(arr, &m, &narr);
	printf("\nArray b: ");
	import_array(b, &nb, &k);

	if (narr != nb) printf("\nUnachievable");
	else 
	{
		product_of_2_matrices(arr, b, c, m, narr, k);
		printf("\nArray arr %dx%d: \n", m, narr);
		display_2_dimensional_arry(arr, m, narr);
		printf("\nArray b %dx%d: \n", narr, k);
		display_2_dimensional_arry(b, nb, k);
		printf("\nArray c %dx%d: \n", m, k);
		display_2_dimensional_arry(c, m, k);
	}
	return 0;
}