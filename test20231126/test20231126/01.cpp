#include <stdio.h>

int main() {
    int i, j, k, rows = 10, columns = 2 * rows - 1;

    // 输出空格以使图案居中
    for (i = 0; i < columns; i++) {
        printf(" ");
    }
    printf("\n");

    // 输出上半部分的菱形
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 输出下半部分的菱形
    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 输出左下角的星号
    for (i = 1; i <= rows - 1; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}