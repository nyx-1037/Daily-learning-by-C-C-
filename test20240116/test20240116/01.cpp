#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水(编程实现)
int main()
{
	int money = 0;
	printf("请输入money值：");
	scanf("%d", &money);
	int total = money;
	int empty = money;
//置换
	while(empty >= 2)
	{
		total += empty /2;
		empty = empty / 2 + empty % 2;
	}
	if (money > 0)
		printf("总共可买%d瓶汽水\n", 2 * money - 1);
	else
		printf("总共可买%d瓶汽水\n",0);

	return 0;
}