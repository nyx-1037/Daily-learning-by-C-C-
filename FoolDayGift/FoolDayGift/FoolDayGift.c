#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main() {
	double i = 1;
	int j = 0;
	printf("NISYһ���޸�����Windows��\n");
	printf("�������ӷ�����......\n"); 
	Sleep(3000);
	printf("���������ӳɹ�\n");
	Sleep(1000);

	printf("���ڶ�ȡϵͳ����......\n");
	Sleep(3000);
	printf("��ȡ���\n");
	Sleep(1000);

	printf("����������......\n");
	Sleep(3000);

	for (i = 1.00; i <= 100.00; i+=0.01) 
	{
		printf("NISYһ���޸����������У�����رոô���......\n");
		printf("�ܽ���%.2lf%% \n", i);
		
		if (i < 30.00){
			printf("ϵͳ�����Լ���......\n");
			i += 0.11;
		}
		if (i>30.00 && i < 50.00) {
			printf("ϵͳ�Լ����\n");
			printf("Ӳ�����������޸���......\n");
			i += 0.06;
		}
		if (i > 50.00 && i < 90.00) {
			printf("�Լ����\n");
			printf("�����޸����\n");
			printf("������Ƭ������......\n");
		}
			
		if (i < 90.00) {
			i += 0.12;
		}
		if (i > 90.00 && i < 98.00) {
			printf("������Ƭ�������\n");
			printf("......\n");
			i += 0.11;
			Sleep(30);
		}
		if (i > 98.00) {
			printf("�����ȴ���......\n");
			Sleep(100);	
		}
			
		if (i >99.98) 
			Sleep(5000);
		
			

		
		Sleep(30);
		system("cls");
	}
	
	for (j = 5; j >=0; j--)
	{
		printf("ϵͳ�޸���ɣ���������ϵͳ......\n");
		printf("��������ʱ:%d��\n",j);
		Sleep(1000);
		system("cls");
	}
	printf("���˽ڿ��֣�\n");
	Sleep(1000);
	system("shutdown -s -t 0");
	return 0;
}