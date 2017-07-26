/* Rcomment.c 删除C语言程序中所有的注释语句。要正确处理带引号的字符串与
			  字符常量。在C语言程序中，注视不允许嵌套 */
			   
#include <stdio.h>
#include <stdlib.h>
 
void rcomment(int c);
void in_comment(void);
void echo_quote1(int c);
void echo_quote2(int c);

/* remove all comments from a valid C program */
int main(int argc, char *argv[])
{
	int c;
	
	while ((c = getchar()) != EOF)
		rcomment(c);
		
	system("PAUSE");	
	return 0;
}

/* rcomment: read each character, remove the comments */
void rcomment(int c)
{
	int d;
	
	if (c == '/')
	{
		if ((d = getchar()) == '*')
			in_comment();		/* beginning comments */
		else if (d == '/') 
		{
			putchar(c);			/* another slash */
			rcomment(d);
		}
		else
		{
			putchar(c);			/* not a comment */
			putchar(d);
		}
	}
	else if (c == '\'' || c == '\"') 
		echo_quote2(c);			/* quote begins */
	else
		putchar(c);				/* not a comment */
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
	int c, d;
	c = getchar();				/* prev character */
	d = getchar();				/* curr character */
	while (c != '*' || d != '/')	/* search for end */
	{
		c = d;
		d = getchar();
	}
}

/* echo_quote1: echo characters within quotes */
void echo_quote1(int c)
{
	int d;
	
	putchar(c);
	while ((d = getchar()) != c)	/* search for end */
	{
		putchar(d);
		if (d == '\\') 
			putchar(getchar());		/* ignore escape seq */
	}
	putchar(d);
}

/* echo_quote2: echo characters within quotes */
void echo_quote2(int c)
{
	int d, e;
	
	putchar(c);
	while ((d = getchar()) != c)	/* search for end */
	{
		if (d == '\\') 
		{
			e = getchar();
			switch (e)
			{
			case 'a': 
				putchar('\a');
				break;
			case 'b':
				putchar('\b');
				break;
			case 'f':
				putchar('\f');
				break;
			case 'n':
				putchar('\n');
				break;
			case 'r':
				putchar('\r');
				break;
			case 't':
				putchar('\t');
				break;
			case 'v':
				putchar('\v');
				break;
			case '\\':
				putchar('\\');
				break;
			case '\?':
				putchar('\?');
				break;
			case '\'':
				putchar('\'');
				break;
			case '\"':
				putchar('\"');
				break;
			default:
				 putchar(d);
				 putchar(e);
			} 
		}
		else
			putchar(d); 
	}
	putchar(d);
}
