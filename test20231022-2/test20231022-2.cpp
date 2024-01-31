#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1 = 0; //定义一个十进制数
    int num2 = 0;//定义一个二进制数
    int i = 0;

    printf("请输入一个十进制数：");
    scanf("%d", &num1);

    while (num1 != 0) {
        i = num1 % 2;
        num2 = num2 * 10 + i;
        num1 = num1 / 2;
    }

    printf("二进制数是：%d\n", num2);

    return 0;
}