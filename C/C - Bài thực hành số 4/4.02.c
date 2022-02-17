/* Cho mảng số nguyên gồm n phần tử được nhập vào từ bàn phím hoặc file. Hãy tìm phần tử thỏa mãn:
a) Là giá trị lớn thứ hai trong mảng
b) Là giá trị nhỏ thứ hai trong mảng
Quy ước rằng nếu min trùng max hoặc min2 trùng max2 thì không có giá trị thỏa mãn.
*/
#include <stdio.h>

void input_arr_and_n(int* arr, int* n);
void find_min_max(int* arr, int n, int* min, int* max);
void search_min2_max2(int* arr, int n, int* min2, int* max2);

int main() {
	int n = 0;
	int arr[100];
	int min2, max2;
	input_arr_and_n(arr, &n);
	search_min2_max2(arr, n, &min2, &max2);
	return 0;
}

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

void find_min_max(int* arr, int n, int* min, int* max) {
	for (int i = 1; i < n; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
}

void search_min2_max2(int* arr, int n, int* min2, int* max2) {
	int min, max;
	find_min_max(arr, n, &min, &max);
	*min2 = max;
	*max2 = min;
	int i;
	for (i = 1; i < n; i++) {
		if (*min2 > arr[i] && arr[i] != min) {
			*min2 = arr[i];
		}
		if (*max2 < arr[i] && arr[i] != max) {
			*max2 = arr[i];
		}
	}
	if (min != *min2 && max != *max2 && *min2 < *max2) {
		printf("\nMIN2 = %d\nMAX2 = %d", *min2, *
			
			max2);
	}
	else {
		printf("\nNot find out");
	}
}