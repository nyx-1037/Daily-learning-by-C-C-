#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

int fun(char* str)
{
	assert(str);
	int i = 0;
	while ((*str)!='\0')
	{
		str++;
		i++;
	}
	return i;
}
int main()
{
	char arr[100] = {  };
	scanf("%s", arr);
	int count = fun(arr);
	printf("%d", count);
	return 0;
}