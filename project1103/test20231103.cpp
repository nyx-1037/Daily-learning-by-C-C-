#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int y;
	int day;
	int h;
	int m;
	printf("������������or��������������������1��������������2\n");
	scanf("%d", &y);
	printf("�������������ڼ���1~7�ֱ��������1�������գ�\n");
	scanf("%d", &day);
	printf("���������ڼ�ʱ���֣���ʹ��24Сʱ��,������15 30����15��30�֣���\n");
	scanf("%d %d", &h, &m);
	if (y == 1)
	{
		printf("����������\n");
		if (day == 1) {
			printf("����������Ҫ����!");
		}
		else if (day == 2) {
			printf("���������!");
		}
		else if (day == 3) {
			printf("����ϲ����!");
		}
		else if (day == 4) {
			printf("�����벻�������鷢����");
		}
		else if (day == 5) {
			printf("���벻�������鷢��!");
		}
		else if (day == 6) {
			printf("�⼸��ᱩ¶�������!");
		}
		else if (day == 7) {
			printf("�ᷢ�����벻������!");
		}
		if (h >= 23 || h < 1) {
			printf("��������ʱ���й��˵�");
		}
		else if (h >= 1 && h < 3) {
			printf("�����ǳ�ʱ�����ǳ��·���");
		}
		else if (h >= 3 && h < 5) {
			printf("��������ʱ���п��˵�");
		}
		else if (h >= 5 && h < 7) {
			printf("������îʱ���й��˵�");
		}
		else if (h >= 7 && h < 9) {
			printf("�����ǳ�ʱ����Զ�����˵�");
		}
		else if (h >= 9 && h < 11) {
			printf("��������ʱ���в跹");
		}
		else if (h >= 11 && h < 13) {
			printf("��������ʱ������ʳ");
		}
		else if (h >= 13 && h < 15) {
			printf("������δʱ����������");
		}
		else if (h >= 15 && h < 17) {
			printf("��������ʱ,�з���֮��");
		}
		else if (h >= 17 && h < 19) {
			printf("��������ʱ���п��˵�");
		}
		else if (h >= 19 && h < 21) {
			printf("��������ʱ������˼��");
		}
		else if (h >= 21 && h < 23) {
			printf("�����Ǻ�ʱ���й�͵�");
		}
	}
	else  if (y == 2)
	{
		printf("����������");
		if (day == 1) {
			printf("ƽ���£���Ҫ��!");
		}
		else if (day == 2) {
			printf("�ᷢ���������!");
		}
		else if (day == 3) {
			printf("���»���������!");
		}
		else if (day == 4) {
			printf("������κ��¶����ܲ���!");
		}
		else if (day == 5) {
			printf("������һ���Ҹ�����!");
		}
		else if (day == 6) {
			printf("���ڻ�õ�����!");
		}
		else if (day == 7) {
			printf("���к�����!");
		}
		if (h >= 23 || h < 1) {
			printf("��������ʱ���о�ʳ����");
		}
		else if (h >= 1 && h < 3) {
			printf("�����ǳ�ʱ������˼��!");
		}
		else if (h >= 3 && h < 5) {
			printf("��������ʱ����ϲ�µ�!");
		}
		else if (h >= 5 && h < 7) {
			printf("������îʱ���������!");
		}
		else if (h >= 7 && h < 9) {
			printf("�����ǳ�ʱ��С����ʧ�Ʋ�!");
		}
		else if (h >= 9 && h < 11) {
			printf("��������ʱ��С�����ֻ�!");
		}
		else if (h > 11 && h < 13) {
			printf("��������ʱ��С��������!");
		}
		else if (h >= 13 && h < 15) {
			printf("������δʱ��������СС��ʧ!");
		}
		else if (h >= 15 && h < 17) {
			printf("��������ʱ����������˼�");
		}
		else if (h >= 17 && h < 19) {
			printf("��������ʱ�������˵���");
		}
		else if (h >= 19 && h < 21) {
			printf("��������ʱ���й����Ļ��棡");
		}
		else if (h >= 21 && h < 23) {
			printf("�����Ǻ�ʱ��С�����ֻ�����");
		}
	}

}


