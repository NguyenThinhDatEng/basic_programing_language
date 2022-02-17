// Đếm số từ của xâu ký tự nhập vào từ bàn phím. Ví dụ xâu “I can’t speak English” gồm 4 từ.
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char str[1000];
	gets(str);
	short count = 0, length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (isblank(str[i + 1]) && isalnum(str[i])) count++;
	}
	if (isalnum(str[length - 1])) count++;
	printf("number of words: %hi", count);
	return 0;
}