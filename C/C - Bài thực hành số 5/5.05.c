//Nhập vào một chuỗi ký tự, hãy đếm số lần xuất hiện của các ký tự chữ cái theo hai cách :
//a.Có phân biệt chữ hoa và chữ thường.
//b.Không phân biệt chữ hoa và chữ thường.
#include<stdio.h>
#include<string.h>

void swap(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void a(char* str, short length)
{
	char mark;
	short count;
	for (int i = 0; i < length; i++)
	{
		mark = str[i];
		count = 1;
		if (isalpha(str[i]))
		{
			for (int j = i + 1; j < length; j++)
			{
				if (mark == str[j])
				{
					count++;
					swap(&str[i + 1], &str[j]);
					i++;
				}
			}
			if (count == 1) printf("%c appears 1 time\n", str[i]);
			else
				printf("%c appears %hi times\n", str[i], count);
		}
	}
}

void b(char* str, short length)
{
	short count = 0;
	for (short i = 0; i < length; i++)
	{
		str[i] = tolower(str[i]);
	}
	a(str, length);
}

int main()
{
	char str[100];
	fgets(str, 99, stdin);
	short length = strlen(str);
	puts("\ndiscrimination\n");
	a(str, length);
	puts("\nindiscrimination\n");
	b(str, length);
	return 0;
}