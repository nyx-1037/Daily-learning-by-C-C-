#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int x, i;

    printf("������һ������ x��0��x��7����");
    scanf("%d", &x);

  
    switch(x)
    { 
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        printf("x �Ķ����Ʊ�ʾΪ��");
        for (i = 7; i >= 0; i--) {
            if (x & (1 << i)) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        break;
    default:
        printf("��x��ֵ�������㷶Χ\n");
        break;
    }
    printf("\n");

    return 0;
}