#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[3][4] = { 0 };
	int M[3][4] = { 0 };
	int i, j, X = 0, Y = 0;
	int count = 0, z = 0;
	
	printf("请输入12个数：");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i][j]);

	int min = arr[0][0];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
		{
			if (arr[i][j] < min)
			{
			min = arr[i][j];
			X = i;
			Y = j;
			}
			if ((arr[i][j] == min) && (i >= X && j >= Y))
			{
				M[i][j] = arr[i][j];
				count++;
			}
		}

	printf("\n该数组的最小元素为%d\n", min,X+1,Y+1);
	printf("一共有%d个的最小元素\n", count);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			if ((M[i][j] != 0) && (z <= count))
			{
				printf("第%d个元素，在第%d行第%d个\n", z + 1, i + 1, j + 1);
				z++;
			}
	return 0;
}