/*
Cho mảng số nguyên arr1 gồm n + m phần tử trong đó n phần tử tùy ý đã đã được nhập vào từ bàn phím hoặc file. 
Mảng arr2 gồm m phần tử tùy ý nhập từ bàn phím hoặc file. Nhập số k sao cho 0 <= k < n. 
Hãy chèn mảng thứ hai(độ dài m) vào vị trí k của mảng thứ nhất. In ra kết quả sau khi chèn.
*/
#include<stdio.h>
#define max 10000

void input_arr2_and_m(int* arr, int* m);
void input_arr1_and_n(int* arr, int* n);
int input_index(int n);
void insert(int* arr1, int* arr2, int m, int n, int index);
void Display(int* arr1, int mn);

int main()
{
    int arr1[max], arr2[max];
    int m, n, mn;
	int index;
	input_arr1_and_n(arr1, &n);
	input_arr2_and_m(arr2, &m);
	mn = m + n;
	index = input_index(n);
	insert(arr1, arr2, m, n, index);
	Display(arr1, mn);
    return 0;
}

void input_arr1_and_n(int* arr, int* n)
{
	do
	{
		printf("import n > 0: n = ");
		scanf("%d", n);
	} while (*n < 1);
	for (int i = 0; i < *n; i++)
	{
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

void input_arr2_and_m(int* arr, int* m) {
	do
	{
		printf("import m > 0: m = ");
		scanf("%d", m);
	} while (*m < 1);
	for (int i = 0; i < *m; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

int input_index(int n) {
	int k;
	do
	{
		printf("import index (0 <= k <= %d): ", n - 1);
		scanf("%d", &k);
	} while (k < 0 || k >= n);
	return k;
}

void insert(int* arr1, int* arr2, int m, int n, int index)
{
	for (int i = m + n - 1; i >= index; i--)
	{
		arr1[i] = arr1[i - m];
	}

	for (int j = 0; j < m; j++)
	{
		arr1[index++] = arr2[j];
	}
}

void Display(int* arr1, int mn)
{
	printf("\n");
	for (int i = 0; i < mn; i++)
	{
		printf("%3d", arr1[i]);
	}
	printf("\n");
}
