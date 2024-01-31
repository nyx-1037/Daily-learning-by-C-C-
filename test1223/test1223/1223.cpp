#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int i, j, t, k;
    int a[10] = { 0 };
    srand((unsigned int)time(NULL));
    for (i = 0; i < 10; i++)
    {

        a[i] = rand() % 100;
    }
    for (k = 10; k > 1; k--)
    {
        for (i = 0, j = 1; i < k - 1; i++, j++)
            if (a[i] < a[j])
                t = a[i], a[i] = a[j], a[j] = t;

        printf("µÚ%dÌË:", 11 - k);
        for (j = 0; j < 10; j++)
            printf("%d ", a[j]);
        printf("\n");
    }
    return 0;
}