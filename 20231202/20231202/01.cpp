#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	int num[10] = { 0 };
	int i;
	while (1)
	{
		for (i = 0; i < 10; i++)
		{
			if (num[i] > 10)
			{
				printf("%s", num[i] % 2 ? "生日快乐 " : "新的一年天天开心  ");
				printf("%s", num[i] % 3 ? "未来可期 " : "今天的寿星是你哦 ");
				Sleep(50);
			}
			else printf("      ");
			if (num[i]-- < 0)
			{
				num[i] = rand() % 20;
			}
	
		}
			system("color 1");
		Sleep(50);
		system("color 2");
		Sleep(50);
		system("color 3");
		Sleep(50);
		system("color 4");
		Sleep(50);
		system("color 5");
		Sleep(50);
		system("color 6");
		Sleep(50);
		system("color 7");
		Sleep(50);
		system("color 8");
		Sleep(50);
		system("color 9");
		Sleep(50);
	}

	printf("\n");

	return 0;
}