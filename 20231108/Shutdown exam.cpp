#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
	printf("请注意，你的电脑将在两分钟内关机，如果输入：“我是猪”后按下Enter键，即可取消关机\n");
again:
	
	printf("请输入：");
	scanf("%s",input);

	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
		printf("成功阻止关机\n");
	}
	else
	{
		printf("输入错误，请重试\n");
		goto again;
	}
	return 0;
}