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
	if (number == -1)
	{
		printf("输入日期非法");
		exit(1);
	} 
	printf("%d年%d月%d日是这一年的第%d天\n", year, month, day, number);
	
	printf("输入年份: ");
	scanf("%d", &year);
	printf("输入天数: ");
	scanf("%d", &number);
	month_day(year, number, &month, &day);
	if (month == -1 && day == -1)
	{
		printf("输入年份或天数非法");
		exit(1);
	} 
	printf("%d年的第%d天是%d月%d日\n", year, number, month, day);
	 
	system("PAUSE");	
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */ 
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p; 
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month < 1 || month > 12)
		return -1;
	if (day < 1 || day > daytab[leap][month])
		return -1;
	p = daytab[leap];
	while (--month) 
		day += *++p; 
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p; 
	
	if (year < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	p = daytab[leap];
	while (yearday > *++p) 
		yearday -= *p; 
	if (p - daytab[leap] > 12 && yearday > daytab[leap][12])
	{
		*pmonth = -1;
		*pday = -1;
	}
	else
	{
		*pmonth = p - *(daytab + leap);
		*pday = yearday;
	}
} 
