#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int y;
	int day;
	int h;
	int m;
	printf("请输入左眼跳or右眼跳，左眼跳请输入1，右眼跳请输入2\n");
	scanf("%d", &y);
	printf("请输入现在星期几，1~7分别代表星期1到星期日：\n");
	scanf("%d", &day);
	printf("请输入现在几时几分（请使用24小时制,如输入15 30代表15点30分）：\n");
	scanf("%d %d", &h, &m);
	if (y == 1)
	{
		printf("您的左眼跳\n");
		if (day == 1) {
			printf("今天有事情要发生!");
		}
		else if (day == 2) {
			printf("心情会很愉快!");
		}
		else if (day == 3) {
			printf("有人喜欢你!");
		}
		else if (day == 4) {
			printf("会有想不到的事情发生！");
		}
		else if (day == 5) {
			printf("有想不到的事情发生!");
		}
		else if (day == 6) {
			printf("这几天会暴露你的秘密!");
		}
		else if (day == 7) {
			printf("会发生意想不到的事!");
		}
		if (h >= 23 || h < 1) {
			printf("现在是子时，有贵人到");
		}
		else if (h >= 1 && h < 3) {
			printf("现在是丑时，有忧愁事发生");
		}
		else if (h >= 3 && h < 5) {
			printf("现在是寅时，有客人到");
		}
		else if (h >= 5 && h < 7) {
			printf("现在是卯时，有贵人到");
		}
		else if (h >= 7 && h < 9) {
			printf("现在是辰时，有远方客人到");
		}
		else if (h >= 9 && h < 11) {
			printf("现在是已时，有茶饭");
		}
		else if (h >= 11 && h < 13) {
			printf("现在是午时，有饮食");
		}
		else if (h >= 13 && h < 15) {
			printf("现在是未时，吉祥如意");
		}
		else if (h >= 15 && h < 17) {
			printf("现在是申时,有飞来之财");
		}
		else if (h >= 17 && h < 19) {
			printf("现在是酉时，有客人到");
		}
		else if (h >= 19 && h < 21) {
			printf("现在是戌时，有相思事");
		}
		else if (h >= 21 && h < 23) {
			printf("现在是亥时，有贵客到");
		}
	}
	else  if (y == 2)
	{
		printf("您的右眼跳");
		if (day == 1) {
			printf("平常事，不要紧!");
		}
		else if (day == 2) {
			printf("会发生不快的事!");
		}
		else if (day == 3) {
			printf("有事会让你生气!");
		}
		else if (day == 4) {
			printf("今天对任何事都不能插手!");
		}
		else if (day == 5) {
			printf("将发生一件幸福的事!");
		}
		else if (day == 6) {
			printf("近期会得到礼物!");
		}
		else if (day == 7) {
			printf("会有好运气!");
		}
		if (h >= 23 || h < 1) {
			printf("现在是子时，有酒食到！");
		}
		else if (h >= 1 && h < 3) {
			printf("现在是丑时，被人思念!");
		}
		else if (h >= 3 && h < 5) {
			printf("现在是寅时，有喜事到!");
		}
		else if (h >= 5 && h < 7) {
			printf("现在是卯时，吉祥和气!");
		}
		else if (h >= 7 && h < 9) {
			printf("现在是辰时，小心损失财产!");
		}
		else if (h >= 9 && h < 11) {
			printf("现在是已时，小心有灾祸!");
		}
		else if (h > 11 && h < 13) {
			printf("现在是午时，小心有凶灾!");
		}
		else if (h >= 13 && h < 15) {
			printf("现在是未时，可能有小小损失!");
		}
		else if (h >= 15 && h < 17) {
			printf("现在是申时，可能有人思念！");
		}
		else if (h >= 17 && h < 19) {
			printf("现在是酉时，有亲人到！");
		}
		else if (h >= 19 && h < 21) {
			printf("现在是戌时，有恭敬的会面！");
		}
		else if (h >= 21 && h < 23) {
			printf("现在是亥时，小心有灾祸到！");
		}
	}

}


