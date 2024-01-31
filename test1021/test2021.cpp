#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int x, i;

    printf("请输入一个整数 x（0≤x≤7）：");
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
        printf("x 的二进制表示为：");
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
        printf("该x的值超出计算范围\n");
        break;
    }
    printf("\n");

    return 0;
}