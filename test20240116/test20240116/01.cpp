#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ(���ʵ��)
int main()
{
	int money = 0;
	printf("������moneyֵ��");
	scanf("%d", &money);
	int total = money;
	int empty = money;
//�û�
	while(empty >= 2)
	{
		total += empty /2;
		empty = empty / 2 + empty % 2;
	}
	if (money > 0)
		printf("�ܹ�����%dƿ��ˮ\n", 2 * money - 1);
	else
		printf("�ܹ�����%dƿ��ˮ\n",0);

	return 0;
}