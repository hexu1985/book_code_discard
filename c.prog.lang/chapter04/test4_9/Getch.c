/* Getch.c */

#include <stdio.h>
#include <string.h>

#define BUFSIZE		100

int buf[BUFSIZE];		/* 用于ungetch函数的缓冲区 */
int bufp = 0;			/* buf中下一个空闲位置 */

/* getch: get a (possibly pushed back) character */
int getch(void)		
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back onto the input */
void ungetch(int c) 	
{
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


