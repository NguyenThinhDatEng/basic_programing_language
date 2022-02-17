// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Xác định đường chạy tăng dài nhất trong mảng trên và xuất hết chúng ra màn hình hoặc file.
#include<stdio.h>
#define max 1000

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

int seek_indexes_and_length_of_range(int* arr, int n, int *b, int *m, int *length)
{
	int count = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] >= arr[i]) count++;
		else
		{
			if (count >= *length && count != 1)
			{
				if (count > *length)
				{
					*length = count;
					*m = 0;
					b[*m] = i - count + 1;
				}
				else
				{
					*m = *m + 1;
					b[*m] = i - count + 1;
				}
			}
			count = 1;
		}
	}
	if (count > * length)
	{
		*m = 0;
		b[*m] = n - count;
		return count;
	}
	else
		if (count == *length) 
		{
			*m = *m + 1;
			b[*m] = n - count;
		}
		return *length;
}

void display(int* arr, int n, int* b, int m, int length)
{
	
	if (length != 1)
	{
		if (length == n)
		{
			printf("starting from arr[0]: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}
		}
		else
		for (int j = 0; j <= m; j++)
		{
			printf("starting from arr[%d]: ", b[j]);
			for (int i = b[j]; i < b[j] + length; i++)
			{
				printf("%d ", arr[i]);

			}
			puts("");
		}
	}
	else
		printf("NOT FOUND");
}

int main()
{
	int arr[max], b[max];
	int n, m = 0;
	int length = 1;
	input_arr_and_n(arr, &n);
	length = seek_indexes_and_length_of_range(arr, n, b, &m, &length);
	display(arr, n, b, m, length);
    return 0;
}