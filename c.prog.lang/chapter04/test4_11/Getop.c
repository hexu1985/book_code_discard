/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

/* getop函数：获取下一个运算符或数值操作数 */
int getop(char s[])
{
	int i, c;
	static int lastc = 0;
	
	if (lastc == 0)
		c = getch();
	else
	{
		c = lastc;
		lastc =0;
	}
	while ((s[0] = c) == ' ' || c == '\t') 
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* 不是数 */
	i = 0;
	if (isdigit(c))		/* 收集整数部分 */
		while (isdigit(s[++i] = c = getch())) 
			;
	if (c == '.') 		/* 收集小数部分 */
		while (isdigit(s[++i] = c = getch())) 
			;
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	return NUMBER;
}
 
