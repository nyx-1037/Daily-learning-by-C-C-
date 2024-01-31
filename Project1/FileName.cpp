#include <stdio.h>

int main() {
    int n, i, num;
    scanf("%d", &n);
    printf("1\n");
    for (i = 2; i <= n; i++) {
        printf("1\n");
        for (num = 1; num < 10; num++) {
            printf("%d\n", pow(num, i));
        }
    }
    for (i = 3; i <= n; i++) {
        printf("%d\n", i);
        for (num = 1; num < 10; num++) {
            printf("%d\n", pow(num, i));
        }
    }
    return 0;
}