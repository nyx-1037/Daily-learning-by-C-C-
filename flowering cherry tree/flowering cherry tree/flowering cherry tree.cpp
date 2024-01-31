#define PI 3.1415926
#define WIDTH 1200
#define HEIGHT 900

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<math.h>



float offsetAngle = PI / 6;
float shortenRate = 0.65;
int isShowAnimation = 1;

float mapValue(float input, float inputMin, float inputMax, float outputMin, float outputMax)
{
	float output;
	if (fabs(input - inputMin) < 0.000001)
		output = outputMin;
	else
		output = (input - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
	return output;
}

float randBetween(float min, float max)
{
	float t = rand() / double(RAND_MAX);

	float r = mapValue(t, 0, 1, min, max);
	return r;
}

void brunch(float x_start, float y_start, float length, float angle, float thickness, int generation)
{
	float x_end, y_end;
	x_end = x_start + length * cos(angle);
	y_end = y_start + length * sin(angle);


	setlinestyle(PS_SOLID, thickness);

	COLORREF color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05);
	setlinecolor(color);

	line(x_start, y_start, x_end, y_end);


	int childGeneration = generation + 1;

	float childLength = shortenRate * length;
	float leftChildLength = childLength * randBetween(0.9, 1.1);
	float rightChildLength = childLength * randBetween(0.9, 1.1);
	float centerChildLength = childLength * randBetween(0.8, 1.1);

	if (childLength >= 2 && childGeneration <= 9)
	{
		float childThickness = thickness * 0.8;
		if (childThickness < 2)
			childThickness = 2;

		if (randBetween(0, 1) < 0.95)
			brunch(x_end, y_end, leftChildLength, angle + offsetAngle * randBetween(1, 1), childThickness, childGeneration);
		if (randBetween(0, 1) < 0.95)
			brunch(x_end, y_end, rightChildLength, angle + offsetAngle * randBetween(-1, -1), childThickness, childGeneration);
		if (randBetween(0, 1) < 0.85)
			brunch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * randBetween(-0.5, 1), childThickness, childGeneration);

	}
	else
	{
		setlinestyle(PS_SOLID, 20);

			COLORREF color = HSVtoRGB(randBetween(300, 350), randBetween(0.2, 0.3), 1);
		setlinecolor(color);
		setfillcolor(color);
		if (childLength <= 4)
			fillcircle(x_end, y_end, 2);
		else
			fillcircle(x_end, y_end, childLength / 2);
	}

	if (isShowAnimation)
	{
		FlushBatchDraw();
		Sleep(1);
	}
}

void startup()
{
	srand(time(0));
	initgraph(WIDTH, HEIGHT);
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	BeginBatchDraw();
	brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1);
	FlushBatchDraw();

}

void update()
{
	MOUSEMSG m;
	if (MouseHit())
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			offsetAngle = mapValue(m.x, 0, WIDTH, PI / 10, PI / 4);

			shortenRate = mapValue(m. y, 0, HEIGHT, 0.7, 0.3);
		}
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			cleardevice();
			brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate,1);
			FlushBatchDraw();
		}
		if (m.uMsg==WM_RBUTTONDOWN)
		{
			if (isShowAnimation == 1)
				isShowAnimation = 0;
			else if (isShowAnimation == 0)
				isShowAnimation = 1;
		}
	}
}




int main()
{
	startup();
	while (1)
		update();

	return 0;
}
