#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i,j,arr[5][5] = { };
	float rel1 = 0, rel2 = 0;
	printf("������˳����ѧ�����ġ�Ӣ�������ѧ��������5��ѧ���ĳɼ���ÿ��ѧ���ɼ�¼����ɰ�enter��������\n");
	for (i = 0; i < 5; i++)
	{
		printf("�������%d��ѧ���ĳɼ���",i + 1);
		for (j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	}
	for (j = 0; j < 5; j++,rel1 = 0)
	{
		for (i = 0; i < 5; i++)
			rel1 += arr[i][j];
		rel1 /= 5;
		printf("��%d����Ŀ��ƽ���ɼ���%.2f\n", j + 1, rel1);
	}
	for (i = 0; i < 5; i++,rel2 = 0)
	{
		for (j = 0; j < 5; j++)
			rel2 += arr[i][j];
		rel2 /= 5;
		printf("��%d��ѧ����ƽ���ɼ���%.2f\n", i + 1, rel2);
	}
	return 0;
}