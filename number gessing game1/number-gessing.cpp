//写一个猜数字小游戏
//1.自动产生一个1-100之间的随机数字
//2.猜数字
//  a.猜对了，就恭喜你，游戏结束
//  b.你猜错了，会告诉你猜大了，还是猜小了，继续猜直到猜对为止
//3.游戏可以一直玩，除非退出游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>//调用srand和rand函数
#include<time.h> //调用time函数

void menu()
{
	printf("*****************************\n");
	printf("**********菜单menu***********\n");
	printf("*****************************\n");
	printf("****猜数字小游戏（1-100）****\n");
	printf("*****************************\n");
	printf("*********1.开始游戏**********\n");
	printf("*********0.退出游戏**********\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*****************************\n\n\n");
}
void game()
{
	//猜数字游戏的实现
	//1.生成随机数
	//rand函数返回了一个0~32767之间的数字
	//时间-时间戳
 
	int ret = rand() % 100 + 1;
	//%100的余数是0-99，然后+1，范围是0-100
	//printf("%d\n",ret)
	
	// 2.猜数字;
	int guess = 0;
	while (1)
	{
		printf("请输入所猜数字：>");
		scanf("%d",&guess);
		if (guess < ret)
		{
			printf("系统提示：猜小了\n\n");
		}
		else if (guess > ret)
		{
			printf("系统提示：猜大了\n\n");
		}
		else
		{
			printf("系统提示：恭喜你，猜对了\n\n");
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
		menu();//打印菜单在屏幕上，调用自定义函数menu
		printf("请选择（0/1）：>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();//跳转到自定义函数game里
			break;
		case 0:
			printf("成功退出游戏\n\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}