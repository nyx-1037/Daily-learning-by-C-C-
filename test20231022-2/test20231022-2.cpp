#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1 = 0; //����һ��ʮ������
    int num2 = 0;//����һ����������
    int i = 0;

    printf("������һ��ʮ��������");
    scanf("%d", &num1);

    while (num1 != 0) {
        i = num1 % 2;
        num2 = num2 * 10 + i;
        num1 = num1 / 2;
    }

    printf("���������ǣ�%d\n", num2);

    return 0;
}