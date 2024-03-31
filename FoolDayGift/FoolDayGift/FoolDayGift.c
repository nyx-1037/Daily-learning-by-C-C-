#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main() {
	double i = 1;
	int j = 0;
	printf("NISY一键修复程序（Windows）\n");
	printf("正在连接服务器......\n"); 
	Sleep(3000);
	printf("服务器连接成功\n");
	Sleep(1000);

	printf("正在读取系统参数......\n");
	Sleep(3000);
	printf("读取完成\n");
	Sleep(1000);

	printf("持续加载中......\n");
	Sleep(3000);

	for (i = 1.00; i <= 100.00; i+=0.01) 
	{
		printf("NISY一键修复程序运行中，请勿关闭该窗口......\n");
		printf("总进度%.2lf%% \n", i);
		
		if (i < 30.00){
			printf("系统极速自检中......\n");
			i += 0.11;
		}
		if (i>30.00 && i < 50.00) {
			printf("系统自检完成\n");
			printf("硬件驱动极速修复中......\n");
			i += 0.06;
		}
		if (i > 50.00 && i < 90.00) {
			printf("自检完成\n");
			printf("驱动修复完成\n");
			printf("磁盘碎片整理中......\n");
		}
			
		if (i < 90.00) {
			i += 0.12;
		}
		if (i > 90.00 && i < 98.00) {
			printf("磁盘碎片整理完成\n");
			printf("......\n");
			i += 0.11;
			Sleep(30);
		}
		if (i > 98.00) {
			printf("持续等待中......\n");
			Sleep(100);	
		}
			
		if (i >99.98) 
			Sleep(5000);
		
			

		
		Sleep(30);
		system("cls");
	}
	
	for (j = 5; j >=0; j--)
	{
		printf("系统修复完成，即将重启系统......\n");
		printf("重启倒计时:%d秒\n",j);
		Sleep(1000);
		system("cls");
	}
	printf("愚人节快乐！\n");
	Sleep(1000);
	system("shutdown -s -t 0");
	return 0;
}