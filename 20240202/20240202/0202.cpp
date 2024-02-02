#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;

	}
	return (*str1 - *str2);
}

int main()
{
	char arr1[] = "abc";
	char arr2[] = "abcd";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
		printf(">\n");
	else if (ret == 0)
		printf("==\n");
	else
		printf("<\n");

	return 0;
}
