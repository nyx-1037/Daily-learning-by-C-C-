#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	float length, width = 0;
	printf("�����볤���εĳ��Ϳ�");
	scanf("%f %f", &length, &width);
	double area = length * width;
	printf("�����ε����Ϊ%lf", area);
	return 0;
}