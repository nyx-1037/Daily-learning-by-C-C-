#include<stdio.h>

int main()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)a++;
	for (j = 4; j >= 0; j--)a++;
	printf("%d", a);
	return 0;
}