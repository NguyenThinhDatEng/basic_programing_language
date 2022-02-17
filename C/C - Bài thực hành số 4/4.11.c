// Hãy viết chương trình tạo ngẫu nhiên các giá trị cho một mảng gồm n phần tử. Mảng được tạo sao cho các phần tử của mảng không trùng nhau theo từng đôi bất kì.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_the_occurrence_of_x(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] == x) 
		{
			return false;
		}
	}
	return true;
}

void input_arr_n(int* arr, int* n) 
{
	int i = 0;
	do
	{
		printf("import n > 0: ");
		scanf("%d", n);
	} while (*n <= 0);
	srand(time(0));
	while (i < *n) 
	{
		int x = rand();
		if (check_the_occurrence_of_x(arr, i, x)) 
		{
			arr[i++] = x;
		}
	}
}

void Display(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%10d", arr[i]);
	}
	printf("\n");
}

int main() {
	int n;
	int arr[1000];
	input_arr_n(arr, &n);
	Display(arr, n);
	return 0;
}