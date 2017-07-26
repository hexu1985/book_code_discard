/* Blank.c 一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替 */
 
#include <stdio.h>
#include <stdlib.h>

#define STYLE_TWO
#define NONBLANK 'a'
 
int main(int argc, char *argv[])
{
	int c, lastc;
	
	lastc = NONBLANK;
#ifdef STYLE_ONE	/* style if */
	printf("This is the style of \"if\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (lastc != ' ')
				putchar(c);
		lastc = c;
	}
#elif defined STYLE_TWO	/* style if-else */
	printf("This is the style of \"if-else\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ')
			putchar(c); 
		else if (lastc != ' ')
			putchar(c);
		lastc = c;
	}
#else	/* style if( || ) */
	printf("This is the style of \"if( || )\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
#endif
	
	system("PAUSE");	
	return 0;
}
