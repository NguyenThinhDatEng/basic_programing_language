// Cho một chuỗi ký tự đầu vào, hãy cho biết nó có bao nhiêu ký tự là nguyên âm, phụ âm, ký tự số và ký tự khác.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char vowel[] = { 'u', 'a', 'e', 'o', 'i', 'A', 'U', 'E', 'O', 'I' };

int main()
{
	char str[100];
	gets(str);
	short arr[] = { 0, 0, 0, 0 };
	short mark;
	for (short i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A'  && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
		{
			mark = 1;
			for (short j = 0; j < strlen(vowel); j++)
			{
				if (str[i] == vowel[j])
				{
					arr[0]++;
					mark = 0;
					break;
				}
			}
			if (mark) arr[1]++;
		}
		else
			if (str[i] >= '0' && str[i] <= '9') arr[2]++;
			else
				arr[3]++;
	}
	printf(" %hi vowels\n %hi consonants\n %hi numbers \n %hi other digits", arr[0], arr[1], arr[2], arr[3]);
	return 0;
}