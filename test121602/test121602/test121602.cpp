#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i,j,arr[5][5] = { };
	float rel1 = 0, rel2 = 0;
	printf("（按照顺序：数学、语文、英语、物理、化学）输入这5个学生的成绩（每个学生成绩录入完成按enter结束）：\n");
	for (i = 0; i < 5; i++)
	{
		printf("请输入第%d个学生的成绩：",i + 1);
		for (j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	}
	for (j = 0; j < 5; j++,rel1 = 0)
	{
		for (i = 0; i < 5; i++)
			rel1 += arr[i][j];
		rel1 /= 5;
		printf("第%d个科目的平均成绩：%.2f\n", j + 1, rel1);
	}
	for (i = 0; i < 5; i++,rel2 = 0)
	{
		for (j = 0; j < 5; j++)
			rel2 += arr[i][j];
		rel2 /= 5;
		printf("第%d个学生的平均成绩：%.2f\n", i + 1, rel2);
	}
	return 0;
}