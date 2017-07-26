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
	
	for (i = 0; i < 26; ++i)
		variable[i] = 0.0;
	while ((type = getop(s)) != EOF) 
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case NAME:
			mathfnc(s);
			break;
		case COMMAND:
			cmdfnc(s);
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
		case '=':
			pop();
			if ((char)var >= 'A' && (char)var <= 'Z')
				variable[var - 'A'] = pop();
			else
				printf("error: no variable name\n");
			break;
		case '?':		/* print top element of the stack */
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case '@':
			push(v);
			break;
		case '#':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if ((char)type >= 'A' && (char)type <= 'Z')
				push(variable[type - 'A']);
			else
				printf("error: unknown command %s\n", s);
			break;
		}
		var = type;
	}
	 
	system("PAUSE");	
	return 0;
}

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
	double op2;
	
	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error: %s not supported\n", s);
}

/* cmdfnc: check string s for supported commond functions */
void cmdfnc(char s[])
{
	double op1, op2;
	
	if (strcmp(s, "c") == 0)
		clear();
	else if (strcmp(s, "d") == 0)
	{
		op2 = pop();
		push(op2);
		push(op2);
	}
	else if(strcmp(s, "s") == 0)
	{
		op1 = pop();
		op2 = pop();
		push(op1);
		push(op2);
	}
	else
		printf("error: %s not supported\n", s);
}
