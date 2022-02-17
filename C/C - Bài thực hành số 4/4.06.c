// Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Tính trung bình cộng các số chẵn, các số lẻ trong dãy. In kết quả ra màn hình hoặc file.
#include <stdio.h>

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

void average_caculation(int* arr, int n, float* ae, float* ao) {
	int count = 0;
	int sumEven = 0;
	int sumOdd = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2) 
		{
			sumOdd += arr[i];
		}
		else {
			sumEven += arr[i];
			count++;
		}
	}
	*ae = (count == n) ? 0 : 1.0f * sumEven / count;
	*ao = (count == 0) ? 0 : 1.0f * sumOdd / (n - count);
}

void display(float ae, float ao) {
	printf("even average = %0.2f\n", ae);
	printf("odd average = %0.2f\n", ao);
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);

	float ae, ao;
	average_caculation(arr, n, &ae, &ao);
	display(ae, ao);

	return 0;
}