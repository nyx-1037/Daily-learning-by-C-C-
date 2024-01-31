#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	float length, width = 0;
	printf("请输入长方形的长和宽：");
	scanf("%f %f", &length, &width);
	double area = length * width;
	printf("长方形的面积为%lf", area);
	return 0;
}