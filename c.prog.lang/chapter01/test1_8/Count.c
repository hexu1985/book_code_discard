/* Count.c 一个统计空格、制表格和换行符个数的程序 */
 
#include <stdio.h>
#include <stdlib.h>

#define STYLE_ONE

/* count blanks, tabs, and newlines */ 
int main(int argc, char *argv[])
{
	int c, nb, nt, nl;
	
	nb = 0;		/* number of blanks */
	nt = 0;		/* number of tabs */
	nl = 0;		/* number of newlines */
#ifdef STYLE_ONE	/* if style */
	printf("This is style of \"if\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c == ' ') 
			++nb;
		if (c == '\t') 
			++nt;
		if (c == '\n') 
			++nl;
	} 
#else	/* if-else style */
	printf("This is style of \"if-else\"\n");
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
#endif
	printf("%d %d %d\n", nb, nt, nl);
	
	system("PAUSE");	
	return 0;
}
