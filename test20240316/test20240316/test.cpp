#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//数据查找
void DATAfind(char arr[], int* num){
	int i = 0;
	if (*num == 0)
		printf("数据库中没有数据\n");

	for (i = 0; i < *num; i++) {
		printf("%s",arr)
	}
}

//数据输入
void DATAincrease(char arr[], int* num){
	scanf
	*num++;
}

//数据修改
void DATAmodify(char arr[], int* num) {

}

//数据删除
void DATAdelete(char arr[], int* num) {

}


int main()
{
	char data[200] = { 0 };
	int count = 0;
	int input;
again:
	do {
		printf("***********************************\n");
		printf("******1、查询数据 2、增加数据******\n");
		printf("******3、修改数据 4、删除数据******\n");
		printf("******0、退出    ******************\n");
		printf("***********************************\n");
		printf("请输入>>");
		scanf("%d", &input);
		printf("\n");
	} while (input);
	switch (input)
	{
	case 0:
		printf("退出成功\n");
		break;
	case 1:
		DATAfind(data, &count);
		break;
	case 2:
		DATAincrease(data, &count);
		break;
	case 3:
		DATAmodify(data, &count);
		break;
	case 4:
		DATAdelete(data, &count);
		break;
	default:
		printf("输入错误,请重新输入\n");
		goto again;
		
	}

	return 0;
}