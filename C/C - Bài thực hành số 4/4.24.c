#include<stdio.h>
#include<math.h>

void input_arr_nxn(int arr[][10], int* n) 
{
	do
	{
		printf("import n > 0: n = ");
		scanf("%d", n);
	} while (*n < 1);
	for (int i = 0; i < *n; i++) 
	{
		for (int j = 0; j < *n; j++)
		{
			printf("arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

int determinant(int arr[][10], int n)
{
	int detnxn = 0;
	if (n == 1) return n;
	if (n == 2) return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
	for (int i = 0; i < n; i++)
	{
		int B[10][10];
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n - 1; k++)
			{
				if (k < i) B[j][k] = arr[j + 1][k];
				else 
					B[j][k] = arr[j + 1][k + 1];
			}
		}
		detnxn += pow(-1, i) * arr[0][i] * determinant(B, n - 1);
	}
	return detnxn;
}

void export_arr_nxn(int a[][10], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[10][10];
	int n;
	int detArr = 0;
	input_arr_nxn(arr, &n);
	int m = n;
	printf("| | = %d", determinant(arr, n));
    return 0;
}