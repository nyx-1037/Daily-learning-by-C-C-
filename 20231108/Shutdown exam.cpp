#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
	printf("��ע�⣬��ĵ��Խ����������ڹػ���������룺������������Enter��������ȡ���ػ�\n");
again:
	
	printf("�����룺");
	scanf("%s",input);

	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
		printf("�ɹ���ֹ�ػ�\n");
	}
	else
	{
		printf("�������������\n");
		goto again;
	}
	return 0;
}