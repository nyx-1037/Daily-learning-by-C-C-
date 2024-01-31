#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>  
#include <stdlib.h>

int main()
{
	int num = 0; // 十进制数  
	char buffer[10]; // 用于存储二进制字符串
	printf("请输入一个十进制数x（0<=x<=7）：");
	scanf_s("%d",&num);
	if (num >= 0 && num<= 7)
	{
		itoa(num, buffer, 2); // 将十进制数转换为二进制字符串

		printf("十进制数 %d 转换为二进制字符串是：000%s\n", num, buffer);
	}
	else
	{
		printf("该数值 %d 超出计算范围",num);
	}
	return  0;
}