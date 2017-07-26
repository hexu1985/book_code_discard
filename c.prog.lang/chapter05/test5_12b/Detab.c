/* Detab.c 将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符
		   终止的地方 */
		   
#include <stdio.h>

#define		MAXLINE		100		/* maximum line size */
#define		TABINC		8		/* default tab increment size */
#define		YES			1
#define		NO			0

void esettab(int argc, char *argv[], char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

/* replace tabs with blanks */
int main(int argc, char *argv[])
{
	char tab[MAXLINE+1];
	
	esettab(argc, argv, tab);	/* initialize tab stops */
	detab(tab);					/* replace tab w/ blanks */
	
	system("PAUSE");	
	return 0;
}

/* detab: replace tab with blanks */
void detab(char *tab)
{
	int c, pos = 1;
	
	while ((c = getchar()) != EOF)
		if (c == '\t')		/* tab character */
		{
			do
				putchar(' ');
			while (tabpos(pos++, tab) != YES);
		}
		else if (c == '\n')	/* newline character */
		{
			putchar(c);
			pos = 1;
		}
		else				/* all other characters */
		{
			putchar(c);
			++pos;
		}
}
