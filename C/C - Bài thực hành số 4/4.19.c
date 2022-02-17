//Hãy tính tổng S(x) = P(x) + Q(x).In kết quả đa thức tổng ra màn hình hoặc file.
#include<stdio.h>

void import_coefficients_of_Px(int* arr, int* n) {
	do
	{
		printf("import number of terms: n = ");
		scanf("%d", n);
	} while (*n < 1);
	for (int i = 0; i < *n; i++) 
	{
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

void import_coefficients_of_Qx(int* arr, int* m) {
	do
	{
		printf("import number of terms: m = ");
		scanf("%d", m);
	} while (*m < 1);
	for (int i = 0; i < *m; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

void plus_Px_and_Qx(int* arr, int* b, int n, int m)
{
	int j = 0;
	for (int i = 0; i < n && j < m; i++)
	{
		arr[i] += b[j];
		b[j++] = arr[i];
	}
}

void display(int* arr, int* b, int m, int n)
{
	printf("f(x) = ");
	if (m > n)
		for (int i = 0; i < m; i++)
		{
			if (b[i])
			{
				printf("%d", b[i]);
				if (i != 0) printf("x^%d", i);
			}
			if (i < m - 1 && b[i + 1]) printf(" + ");
		}
	else
		for (int i = 0; i < n; i++)
		{
			if (arr[i])
			{
				printf("%d", arr[i]);
				if (i != 0) printf("x^%d", i);
			}
			if (i < n - 1 && arr[i + 1]) printf(" + ");
		}
}
int main()
{
	int arr[1000], b[1000];
	int n, m;
	import_coefficients_of_Px(arr, &n);
	import_coefficients_of_Qx(b, &m);
	plus_Px_and_Qx(arr, b, n, m);
	display(arr, b, m, n);
    return 0;
}