#include <stdio.h>

int main() {
    int i, j, k, rows = 10, columns = 2 * rows - 1;

    // ����ո���ʹͼ������
    for (i = 0; i < columns; i++) {
        printf(" ");
    }
    printf("\n");

    // ����ϰ벿�ֵ�����
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // ����°벿�ֵ�����
    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // ������½ǵ��Ǻ�
    for (i = 1; i <= rows - 1; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}