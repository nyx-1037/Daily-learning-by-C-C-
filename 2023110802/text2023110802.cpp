#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
	printf("可以做我的女朋友吗？\n（同意请求即可取消注销）\n");
again:

	printf("请输入（可以/不可以）：");
	scanf("%s", input);
	while (1) {
		if (strcmp(input, "可以") == 0)
		{
			system("shutdown -a");
			printf("\n爱你么么哒~\n\n");
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
			printf("系统提示：成功阻止关机\n\n");
			break;
		}
		if (strcmp(input, "不可以") == 0)
		{
			printf("\n答应我，好不好嘛~\n\n");
			printf("\n输入错误，即将关机，请重试\n\n");
			goto again;
		}
		else
		{
			printf("\n系统提示：输入的字符串无效,请重试 \n");
			goto again;
		}
	}
	system("pause");

	return 0;
}