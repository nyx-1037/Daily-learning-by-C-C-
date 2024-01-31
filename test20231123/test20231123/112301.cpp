#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
int is_leap_year(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}
int days_in_month(int year, int month) {
    int days = 0;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        days = is_leap_year(year) ? 29 : 28;
        break;
    default:
        return 0;
    }
    return days;
}
int main() {
    int day, month, year;
    printf("请输入日期（格式：年 月 日）：");
    if (scanf("%d %d %d", &year,&month, &day ) != 3) {
        printf("无效的输入，请按照格式输入：年 月 日\n");
        return 1;
    }
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > days_in_month(year, month)) {
        printf("无效的输入，请输入合法的日期：年 月 日\n");
        return 1;
    }
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += days_in_month(year, i);
    }
    days += day;
    printf("该日期是本年度的第 %d 天。\n", days);
    return 0;
}