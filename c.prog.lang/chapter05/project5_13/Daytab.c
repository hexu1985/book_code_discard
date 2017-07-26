/* Daytab.c */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char *argv[])
{
	int year, day, month;
	int number;
	
	printf("输入日期(MM/DD/YYYY): ");
	scanf("%d/%d/%d", &month, &day, &year);
	number = day_of_year(year, month, day);
	printf("%d年%d月%d日是这一年的第%d天\n", year, month, day, number);
	
	printf("输入年份: ");
	scanf("%d", &year);
	printf("输入天数: ");
	scanf("%d", &number);
	month_day(year, number, &month, &day);
	printf("%d年的第%d天是%d月%d日\n", year, number, month, day);
	 
	system("PAUSE");	
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year函数：将某月某日的日期表示形式转换为某年中第几天的表示形式 */ 
int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day函数：将某年中第几天的日期表示形式转换为某月某日的表示形式 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
} 
