#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
	printf("�������ҵ�Ů������\n��ͬ�����󼴿�ȡ��ע����\n");
again:

	printf("�����루����/�����ԣ���");
	scanf("%s", input);
	while (1) {
		if (strcmp(input, "����") == 0)
		{
			system("shutdown -a");
			printf("\n����ôô��~\n\n");
			Sleep(100);
			printf("     *****         *****      \n");
			Sleep(100);
			printf("   **********   **********    \n");
			Sleep(100);
			printf("   ***********************    \n");
			Sleep(100);
			printf("    *********************     \n");
			Sleep(100);
			printf("     *******************      \n");
			Sleep(100);
			printf("       ***************        \n");
			Sleep(100);
			printf("         ***********           \n");
			Sleep(100);
			printf("           *******            \n");
			Sleep(100);
			printf("            *****             \n");
			Sleep(100);
			printf("              *               \n");
			Sleep(100);
			printf("ϵͳ��ʾ���ɹ���ֹ�ػ�\n\n");
			break;
		}
		if (strcmp(input, "������") == 0)
		{
			printf("\n��Ӧ�ң��ò�����~\n\n");
			printf("\n������󣬼����ػ���������\n\n");
			goto again;
		}
		else
		{
			printf("\nϵͳ��ʾ��������ַ�����Ч,������ \n");
			goto again;
		}
	}
	system("pause");

	return 0;
}