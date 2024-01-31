#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"
void test()
{
	int ch = 0;
	do
	{
		Snake snake = { 0 };//创建了贪吃蛇
		//1. 游戏开始 - 初始化游戏
		GameStart(&snake);
		//2. 游戏运行 - 游戏的正常运行过程
		GameRun(&snake);
		//3. 游戏结束 - 游戏善后（释放资源）
		GameEnd(&snake);
		SetPos(20, 18);
		printf("再来一局吗?(Y/N):");
		ch = getchar();
		getchar();// 清理掉\n
	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 27);
}
int main()
{
	//设置程序适应本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	test();
	return 0;
}