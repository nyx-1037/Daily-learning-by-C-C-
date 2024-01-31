#include <stdio.h>

int main() {
    int x, i;

    printf("请输入一个十进制数 (0-7): ");
    scanf_s("%d", &x);
  

    if (x >= 0 && x <= 7)
    {
        printf("则x的二进制数为：");
        printf("00000");
        while (x != 0) {
            i = x % 2;
            printf("%d", i);
            x = x / 2;
        }
        if (x == 4)
        {
            printf("00\n");
        }
        else if (x == 0,2,6)
        {
            printf("0\n");
        }
        

     
    }
    else
        printf("该x的值超出计算范围");

    return 0;
}