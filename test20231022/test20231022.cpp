#include <stdio.h>

int main() {
    int x, i;

    printf("������һ��ʮ������ (0-7): ");
    scanf_s("%d", &x);
  

    if (x >= 0 && x <= 7)
    {
        printf("��x�Ķ�������Ϊ��");
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
        printf("��x��ֵ�������㷶Χ");

    return 0;
}