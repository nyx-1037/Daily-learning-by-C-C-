#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[3][4] = { 0 };
	int M[3][4] = { 0 };
	int i, j, X = 0, Y = 0;
	int count = 0, z = 0;
	
	printf("������12������");
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

	printf("\n���������СԪ��Ϊ%d\n", min,X+1,Y+1);
	printf("һ����%d������СԪ��\n", count);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			if ((M[i][j] != 0) && (z <= count))
			{
				printf("��%d��Ԫ�أ��ڵ�%d�е�%d��\n", z + 1, i + 1, j + 1);
				z++;
			}
	return 0;
}