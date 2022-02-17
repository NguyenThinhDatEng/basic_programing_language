// Cho mảng số nguyên gồm n phần tử tùy ý.Hãy nhập giá trị nguyên x nào đó và xác định phần tử có giá trị gần x nhất.Giá trị k nào đó gọi là gần x nhất nếu | k - x | gần với 0 nhất.
#include <stdio.h>
#include <math.h>

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


int look_for_minimum_absolute_value(int* arr, int n, int x) {
	int value = abs(arr[0] - x);
	for (int i = 1; i < n; i++) {
		if (abs(arr[i] - x) < value) {
			value = abs(arr[i] - x);
		}
	}
	return value;
}

void discover_the_remaining_number_if_available(int *arr, int n, int value, int x) 
{
	int mark = 0, count = 0;
	if (value)
		for (int i = 0; i < n; i++) {
			if (arr[i] == x - value || arr[i] == x + value)
			{
				if (count == 0)
				{
					mark = arr[i];
					count++;
				}
				if (arr[i] != mark)
				{
					printf("%d", arr[i]);
					break;
				}
				printf("%d ", arr[i]);
			}
		}
	else
		printf("%d", x);
}

int main() {
	int n, arr[100];
	int x;
	input_arr_and_n(arr, &n);
	printf("Import x: ");
	scanf("%d", &x);
	int value = look_for_minimum_absolute_value(arr, n, x);
	discover_the_remaining_number_if_available(arr, n, value, x);
	return 0;
}