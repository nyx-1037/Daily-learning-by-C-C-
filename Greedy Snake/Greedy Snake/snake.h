#pragma once
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

#define POS_X 24
#define POS_Y 5

#define KEY_PRESS(VK)  ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )

enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,//正常运行
	END_NORMAL,//按ESC退出
	KILL_BY_WALL,
	KILL_BY_SELF
};

//贪吃蛇结点的描述
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

//贪吃蛇的结构
typedef struct Snake
{
	pSnakeNode _pSnake;//指向贪吃蛇头结点的指针
	pSnakeNode _pFood;//指向食物结点的指针
	int _Score;//贪吃蛇累计的总分
	int _FoodWeight;//一个食物的分数
	int _SleepTime;//每走一步休息的时间，时间越短，速度越快，时间越长，速度越慢
	enum DIRECTION _Dir;//描述蛇的方向
	enum GAME_STATUS _Status;//游戏的状态：正常、退出、撞墙、吃到自己
}Snake, * pSnake;

//游戏开始 - 完成游戏的初始化动作
void GameStart(pSnake ps);

//定位坐标
void SetPos(short x, short y);

//游戏开始的欢迎界面
void WelComeToGame();

//打印地图
void CreateMap();

//初始化贪吃蛇
void InitSnake(pSnake ps);

//创建食物
void CreateFood(pSnake ps);

//游戏的正常运行
void GameRun(pSnake ps);

//打印帮助信息
void PrintHelpInfo();

//游戏暂定和恢复
void Pause();

//蛇的移动
void SnakeMove(pSnake ps);

//判断蛇头到达的坐标处是否是食物
int NextIsFood(pSnake ps, pSnakeNode pnext);

//吃掉食物
void EatFood(pSnake ps, pSnakeNode pnext);

//不吃食物
void NoFood(pSnake ps, pSnakeNode pnext);

//蛇是否撞墙
void KillByWall(pSnake ps);

//蛇是否自杀
void KillBySelf(pSnake ps);

//游戏结束后的善后处理
void GameEnd(pSnake ps);
