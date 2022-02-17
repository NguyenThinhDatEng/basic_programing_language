// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Tìm số lần xuất hiện của từng phần tử trong mảng này.
#include<stdio.h>
#define max 10000

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

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void count_arrange_export(int* arr, int n)
{
	int mark;
	int count;
	for (int i = 0; i < n; i++)
	{
		mark = arr[i];
		count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (mark == arr[j])
			{
				count++;
				swap(&arr[i + 1], &arr[j]);
				i++;
			}
		}
		(count == 1)? printf("%d appears 1 time\n", arr[i]) : printf("%d appears %d times\n", arr[i], count);
	}
}
int main()
{
	int arr[max], n = 0;
	input_arr_and_n(arr, &n);

	count_arrange_export(arr, n);
    return 0;
}