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
	double op1, op2;
	char s[MAXOP];
	double tmp;
	
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
		case '?':		/* print top element of the stack */
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c':		/* clear the stack */
			clear();
			break;
		case 'd':		/* duplicate top elem. of the stack */
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':		/* swap the top two elements */
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '=':
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
