//Hãy chuẩn hoá một xâu ký tự cho trước : loại bỏ các dấu cách thừa + chuyển ký tự đầu mỗi từ thành chữ hoa, các ký tự khác thành chữ thường
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void remove_space_below(char* str)
{
	short length = strlen(str);
	short i = length - 1;
	while (isblank(str[i]))
	{
		str[i--] = '\0';
	}
}

void delete_space_above(char* str)
{
	short length = strlen(str);
	short i = 0;
	while (isblank(str[i]))
	{
		i++;
	}
	if (isblank(str[0]))
		for (short j = 0; j <= length - i; j++)
		{
			str[j] = str[j + i];
		}
}

void remove_space_middle(char *str)
{
	short length = strlen(str);
	short mark;
	for (short i = length - 2; i > 1; i--)
	{
		if (isblank(str[i]) && isblank(str[i - 1]))
		{
			mark = i - 1;
			while (isblank(str[mark]) && isblank(str[mark - 1]))
			{
				mark--;
			}
			short j = mark;
			while (i <= length)
			{
				str[++j] = str[++i];
			}
			i = mark - 1;
			length = strlen(str);
		}
	}
}

void upper_first_digit_of_word(char* str)
{
	short length = strlen(str);
	str[0] = toupper(str[0]);
	for (int i = 1; i < length - 1; i++)
	{
		if (isblank(str[i]))
		{
			str[i + 1] = toupper(str[i + 1]);
		}
	}
}

void lower_below_digit(char* str)
{
	short length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			while (isalpha(str[++i]))
			{
				str[i] = tolower(str[i]);
			}
	}
}

int main()
{
	char str[100];
	gets(str);
	remove_space_below(str);
	delete_space_above(str);
	remove_space_middle(str);
	upper_first_digit_of_word(str);
	lower_below_digit(str);
	puts(str);
	return 0;
}
