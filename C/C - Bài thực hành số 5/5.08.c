// Nhập họ và tên theo cấu trúc : họ - đệm - tên và chuyển xâu đó sang biểu diễn theo cấu trúc tên - đệm - họ.
#include<stdio.h>
#include<string.h>

short seek_first_blank(char* str)
{
	short i = 0;
	while (isalpha(str[i]))
	{
		i++;
	}
	return i;
}

short seek_last_blank(char* str)
{
	short i = strlen(str) - 1;
	while (isalpha(str[i]))
	{
		i--;
	}
	return i;
}

int main()
{
	char str[100], surname[33], name[33], middlename[33];
	gets(str);
	short j = 0;
	short firstSpace = seek_first_blank(str);
	short lastSpace = seek_last_blank(str);

	strncpy(surname, str, firstSpace);
	surname[firstSpace] = '\0';

	for (short i = lastSpace + 1; i <= strlen(str); i++)
	{
		name[j++] = str[i];
	}

	j = 0;
	for (short i = firstSpace; i <= lastSpace; i++)
	{
		middlename[j++] = str[i];
	}
	middlename[j] = '\0';

	strcat(name, middlename);
	strcat(name, surname);
	puts(name);
	return 0;
}
