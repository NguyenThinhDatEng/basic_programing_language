//Cho mảng số nguyên gồm n phần tử tùy ý nhập từ bàn phím hoặc file. Kiểm tra xem mảng này có đối xứng hay không. Mảng đối xứng là mảng có các giá trị theo thứ tự ngược 
//và xuôi như nhau. Ví dụ: 1 2 3 6 3 2 1 là mảng đối xứng.
#include <stdio.h>
#include <stdbool.h>

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


bool check(int* arr, int n) {
	for (int i = 0; i <= n / 2; i++) {
		if (arr[i] != arr[n - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	int arr[100];
	input_arr_and_n(arr, &n);
	if (check(arr, n)) {
		printf("True\n");
	}
	else {
		printf("false\n");
	}
	return 0;
}
