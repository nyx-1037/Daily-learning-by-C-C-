#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float a, b = 0;
	float min = 0;
	printf("请同时输入两个实数：");
	scanf("%f %f", &a,&b);
	min = a < b ? a : b;
	printf("则这两个数中较小的是：%f", min);
	return 0;
}