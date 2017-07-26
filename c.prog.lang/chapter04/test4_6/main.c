/* main.c 逆波兰计算器 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Calc.h"

#define MAXOP	100		/* 操作数或运算符的最大长度 */

/* 逆波兰计算器 */ 
int main(int argc, char *argv[])
{
	int i, type, var = 0;
	double op2, v;
	char s[MAXOP];
	double variable[26];
	
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;
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
		case '=':
			pop();
			if ((char)var >= 'A' && (char)var <= 'Z')
				variable[var - 'A'] = pop();
			else
				printf("error: no variable name\n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if ((char)type >= 'A' && (char)type <= 'Z')
				push(variable[type - 'A']);
			else if (type == 'v')
				push(v);
			else
				printf("error: unkown command %s\n", s);
			break;
		}
		var = type;
	}
	 
	system("PAUSE");	
	return 0;
}
