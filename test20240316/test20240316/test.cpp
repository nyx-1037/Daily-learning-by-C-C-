#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//���ݲ���
void DATAfind(char arr[], int* num){
	int i = 0;
	if (*num == 0)
		printf("���ݿ���û������\n");

	for (i = 0; i < *num; i++) {
		printf("%s",arr)
	}
}

//��������
void DATAincrease(char arr[], int* num){
	scanf
	*num++;
}

//�����޸�
void DATAmodify(char arr[], int* num) {

}

//����ɾ��
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
		printf("******1����ѯ���� 2����������******\n");
		printf("******3���޸����� 4��ɾ������******\n");
		printf("******0���˳�    ******************\n");
		printf("***********************************\n");
		printf("������>>");
		scanf("%d", &input);
		printf("\n");
	} while (input);
	switch (input)
	{
	case 0:
		printf("�˳��ɹ�\n");
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
		printf("�������,����������\n");
		goto again;
		
	}

	return 0;
}