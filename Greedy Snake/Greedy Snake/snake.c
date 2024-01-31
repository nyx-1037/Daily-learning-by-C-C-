#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

//设置光标的坐标
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//获取标准输出的句柄(用来标识不同设备的数值)
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}

//打印欢迎界面
void WelComeToGame()
{
	//定位光标
	SetPos(40, 14);
	printf("欢迎来到贪吃蛇小游戏");
	SetPos(40, 25);
	system("pause");//pause是暂停
	system("cls");
	SetPos(20, 14);
	printf("使用 ↑ . ↓ . ← . → . 分别控制蛇的移动, F3是加速，F4是减速");
	SetPos(40, 25);
	system("pause");
	system("cls");
}

//创建墙体
void CreateMap()
{
	//上
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, 26);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

//初始化蛇
void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		cur->next = NULL;

		//头插法
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	//打印蛇身
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	ps->_Status = OK;
	ps->_Score = 0;
	ps->_pFood = NULL;
	ps->_SleepTime = 200;
	ps->_FoodWeight = 10;
	ps->_Dir = RIGHT;
}

//创建食物
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);//x坐标必须是2的倍数

	//坐标不能和蛇的身体冲突
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		//比较坐标
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}

	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	ps->_pFood = pFood;

	//打印食物
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}

//游戏开始
void GameStart(pSnake ps)
{
	//控制台窗口的设置
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");

	//光标影藏掉
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//影藏光标操作
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态

	//打印欢迎界面
	WelComeToGame();
	//创建地图
	CreateMap();
	//初始化贪食蛇
	InitSnake(ps);
	//创建食物
	CreateFood(ps);
}

//打印帮助信息
void PrintHelpInfo()
{
	SetPos(64, 15);
	printf("1.不能撞墙，不能咬到自己");
	SetPos(64, 16);
	printf("2.使用 ↑.↓.←.→ 分别控制蛇的移动");
	SetPos(64, 17);
	printf("3.F3加速，F4减速");
	SetPos(64, 18);
	printf("4.ESC-退出, 空格-暂停游戏");

	SetPos(64, 20);
	printf("@TSQ");
}

//休眠
void Pause()
{
	while (1)
	{
		Sleep(100);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//下个节点
int NextIsFood(pSnake ps, pSnakeNode pnext)
{
	if (ps->_pFood->x == pnext->x && ps->_pFood->y == pnext->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//吃掉食物
void EatFood(pSnake ps, pSnakeNode pnext)
{
	//头插
	pnext->next = ps->_pSnake;
	ps->_pSnake = pnext;

	//打印蛇
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	free(ps->_pFood);
	ps->_Score += ps->_FoodWeight;

	CreateFood(ps);//新创建食物
}

//不吃食物
void NoFood(pSnake ps, pSnakeNode pnext)
{
	//头插
	pnext->next = ps->_pSnake;
	ps->_pSnake = pnext;

	//打印蛇身
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

//蛇是否撞墙
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 ||
		ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 ||
		ps->_pSnake->y == 26)
		ps->_Status = KILL_BY_WALL;
}

//蛇是否自杀
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (ps->_pSnake->x == cur->x && ps->_pSnake->y == cur->y)
		{
			ps->_Status = KILL_BY_SELF;
		}
		cur = cur->next;
	}
}

//🐍蛇移动
void SnakeMove(pSnake ps)
{
	pSnakeNode pNext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNext == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	pNext->next = NULL;

	switch (ps->_Dir)
	{
	case UP:
		pNext->x = ps->_pSnake->x;
		pNext->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNext->x = ps->_pSnake->x;
		pNext->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNext->x = ps->_pSnake->x - 2;
		pNext->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNext->x = ps->_pSnake->x + 2;
		pNext->y = ps->_pSnake->y;
		break;
	}

	//判断蛇头到达的坐标处是否是食物
	if (NextIsFood(ps, pNext))
	{
		//吃掉食物
		EatFood(ps, pNext);
	}
	else
	{
		//不吃食物
		NoFood(ps, pNext);
	}

	//蛇是否撞墙
	KillByWall(ps);

	//蛇是否自杀
	KillBySelf(ps);
}

//游戏运行
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("得分:%05d", ps->_Score);
		SetPos(64, 11);
		printf("每个食物的分数:%2d", ps->_FoodWeight);

		if (KEY_PRESS(VK_UP) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->_Status = END_NORMAL;
			break;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_F3))//加速
		{
			if (ps->_SleepTime >= 80)
			{
				ps->_SleepTime -= 30;
				ps->_FoodWeight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))//减速
		{
			if (ps->_SleepTime < 320)
			{
				ps->_SleepTime += 30;
				ps->_FoodWeight -= 2;
			}
		}

		Sleep(ps->_SleepTime);
		SnakeMove(ps);
	} while (ps->_Status == OK);
}

//游戏结束
void GameEnd(pSnake ps)
{
	SetPos(20, 12);
	switch (ps->_Status)
	{
	case END_NORMAL:
		printf("您主动退出游戏\n");
		break;
	case KILL_BY_SELF:
		printf("自杀了,游戏结束\n");
		break;
	case KILL_BY_WALL:
		printf("撞墙了，游戏结束\n");
		break;
	}
	//释放蛇身的结点
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
	ps->_pSnake = NULL;

}