/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

/* getop: get next operator or numeric operand; pointer ver */
int getop(char *s)
{
	int c;
	
	while ((*s = c = getch()) == ' ' || c == '\t') 
		;
	*(s + 1) = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
	if (isdigit(c))		/* collect integer part */
		while (isdigit(*++s = c = getch())) 
			;
	if (c == '.') 		/* collect fraction part */
		while (isdigit(*++s = c = getch())) 
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
 
