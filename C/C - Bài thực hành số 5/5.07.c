// Nhập một xâu ký tự và tìm từ dài nhất, chỉ rõ vị trí của nó trong xâu đó. Nếu có nhiều từ có độ dài giống nhau thì chọn từ đầu tiên.

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int index_of_word(char* str)
{
	short length = strlen(str);
	short count, max = 0;
	short index = -1;
	for (int i = 0; i < length; i++)
	{
		count = 0;
		while (isalnum(str[i]))
		{
			count++;
			i++;
		}
		if (count > max)
		{
			max = count;
			index = i - count;
		}
	}
	printf("longest world: ");
	for (int i = index; isalnum(str[i]); i++)
	{
		printf("%c", str[i]);
	}
	return index;
}

int main()
{
	char str[200];
	fgets(str, 199, stdin);
	printf("\nindex = %d", index_of_word(str));
	return 0;
}