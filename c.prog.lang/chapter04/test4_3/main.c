/* main.c 逆波兰计算器 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Calc.h"

#define MAXOP	100		/* 操作数或运算符的最大长度 */

/* 逆波兰计算器 */ 
int main(int argc, char *argv[])
{
	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) 
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) 
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break; 
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unkown command %s\n", s);
			break;
		}
	}
	 
	system("PAUSE");	
	return 0;
}
