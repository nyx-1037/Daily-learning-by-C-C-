#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float a, b = 0;
	float min = 0;
	printf("��ͬʱ��������ʵ����");
	scanf("%f %f", &a,&b);
	min = a < b ? a : b;
	printf("�����������н�С���ǣ�%f", min);
	return 0;
}