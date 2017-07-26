/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

/* getop: get next operator, numeric operand, or math fnc */
int getop(char s[])
{
	int c, i;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		;
	s[1] = '\0';
	i = 0;
	if (islower(c))			/* command or NAME */
	{
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);		/* went one char too far */
		if (strlen(s) > 1)
			return NAME;	/* >1 char; it is NAME */
		else
			return c;
	}
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */	
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch())) 
			;
	if (c == '.') 		/* collect fraction part */
		while (isdigit(s[++i] = c = getch())) 
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
 
