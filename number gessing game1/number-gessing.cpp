//дһ��������С��Ϸ
//1.�Զ�����һ��1-100֮����������
//2.������
//  a.�¶��ˣ��͹�ϲ�㣬��Ϸ����
//  b.��´��ˣ��������´��ˣ����ǲ�С�ˣ�������ֱ���¶�Ϊֹ
//3.��Ϸ����һֱ�棬�����˳���Ϸ
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>//����srand��rand����
#include<time.h> //����time����

void menu()
{
	printf("*****************************\n");
	printf("**********�˵�menu***********\n");
	printf("*****************************\n");
	printf("****������С��Ϸ��1-100��****\n");
	printf("*****************************\n");
	printf("*********1.��ʼ��Ϸ**********\n");
	printf("*********0.�˳���Ϸ**********\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*****************************\n\n\n");
}
void game()
{
	//��������Ϸ��ʵ��
	//1.���������
	//rand����������һ��0~32767֮�������
	//ʱ��-ʱ���
 
	int ret = rand() % 100 + 1;
	//%100��������0-99��Ȼ��+1����Χ��0-100
	//printf("%d\n",ret)
	
	// 2.������;
	int guess = 0;
	while (1)
	{
		printf("�������������֣�>");
		scanf("%d",&guess);
		if (guess < ret)
		{
			printf("ϵͳ��ʾ����С��\n\n");
		}
		else if (guess > ret)
		{
			printf("ϵͳ��ʾ���´���\n\n");
		}
		else
		{
			printf("ϵͳ��ʾ����ϲ�㣬�¶���\n\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();//��ӡ�˵�����Ļ�ϣ������Զ��庯��menu
		printf("��ѡ��0/1����>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();//��ת���Զ��庯��game��
			break;
		case 0:
			printf("�ɹ��˳���Ϸ\n\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}