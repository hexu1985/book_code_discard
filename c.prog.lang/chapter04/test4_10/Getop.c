/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

#define MAXLINE		100

int getline(char line[], int limit);

int li = 0;				/* input line index */
char line[MAXLINE];		/* one input line */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int c, i;
	
	if (line[li] == '\0')
		if (getline(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;			/* not a number */
	i = 0;
	if (isdigit(c))			/* collect integer part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')			/* collect fraction part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;	
}

int getline(char s[], int lim)
{
	int c, i;
	
	for (i =0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c = '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
