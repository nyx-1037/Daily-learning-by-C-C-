#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	float V, result = 0;
	char ch1;
	char ch2;
again:
	printf("��������������L����");
	scanf("%f", &V);
	getchar();
	printf("\n");
	printf("�������������ͣ�A/B/C����");
	scanf("%c", &ch1);
	getchar();
	printf("\n");
	printf("������������ͣ�F/M/E����");
	scanf("%c", &ch2);
	printf("\n");

	switch (ch1)
	{
	case 'A':
		switch (ch2)
		{
		case 'F':
			result = 4.75 * V;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'M':
			result = 4.75 * V * 0.9;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'E':
			result = 4.75 * V * 0.95;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		}
		break;
	case 'B':
		switch (ch2)
		{
		case 'F':
			result = 5.20 * V;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'M':
			result = 5.20 * V * 0.9;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'E':
			result = 5.20 * V * 0.95;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		}
		break;
	case 'C':
		switch (ch2)
		{
		case 'F':
			result = 5.75 * V;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'M':
			result = 5.75 * V * 0.9;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		case 'E':
			result = 5.75 * V * 0.95;
			printf("Ӧ֧���ķ���Ϊ%f\n", result);
			break;
		}
		break;

	default:
		printf("��������ݲ��Ϸ�������������\n");
		goto again;


	}



	return 0;
}
