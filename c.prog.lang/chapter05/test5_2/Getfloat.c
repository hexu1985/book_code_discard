/* Getfloat.c */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getfloat(float *pn);

int main(int argc, char *argv[])
{
	float test;
	int c;
	
	printf("Enter a number: ");
	getfloat(&test);
	printf("test = [%f]\n", test);
	
	c = getch();
	printf("c = [%c]", c);
	printf("\n");
	
	system("PAUSE");
	return 0;
}	

#define BUFSIZE		100

char buf[BUFSIZE];		/* 用于ungetch函数的缓冲区 */
int bufp = 0;			/* buf中下一个空闲位置 */

int getch(void)			/* 取一个字符(可能是压回的字符) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 	/* 把字符压回到输入中 */
{
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getfloat: get next floating-point number from input into *pn */
int getfloat(float *pn) 
{
	int c, sign;
	float power;
	
	while (isspace(c = getch())) 	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') 
	{
		ungetch(c);		/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') 
		c = getch();
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');		/* integer part */
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');		/* fractional part */
		power *= 10.0;
	}
	*pn *= sign / power;					/* final number */
	if (c != EOF)
		ungetch(c);
	return c;
} 
 
