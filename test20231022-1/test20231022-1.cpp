#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>  
#include <stdlib.h>

int main()
{
	int num = 0; // ʮ������  
	char buffer[10]; // ���ڴ洢�������ַ���
	printf("������һ��ʮ������x��0<=x<=7����");
	scanf_s("%d",&num);
	if (num >= 0 && num<= 7)
	{
		itoa(num, buffer, 2); // ��ʮ������ת��Ϊ�������ַ���

		printf("ʮ������ %d ת��Ϊ�������ַ����ǣ�000%s\n", num, buffer);
	}
	else
	{
		printf("����ֵ %d �������㷶Χ",num);
	}
	return  0;
}