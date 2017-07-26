/* 将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隙不变 */
 
#include <stdio.h>
#include <stdlib.h>

#define TABINC		8		/* number of blanks necessary */

/* replace strings of blanks with tabs and blanks */
int main(int argc, char *argv[])
{
	int c, nb, nt, pos;
	
	nb = 0;			/* # of blanks necessary */
	nt = 0; 		/* # of tabs necessary */
	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ')
		{
			if (pos % TABINC != 0)
				++nb;		/* increment # of blanks */
			else
			{
				nb = 0;		/* reset # of blanks */
				++nt;		/* one more tab */
			}
		}
		else
		{
			for ( ; nt > 0; --nt)
				putchar('\t');		/* output tab(s) */
			if (c == '\t')			/* forget the blank(s) */
				nb = 0;
			else
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
			{
				if ((pos + (TABINC - (pos - 1) % TABINC) - 1) != (((pos / TABINC) + 1) * TABINC))
				{
					printf("\n#ERROR#\n");
					exit(1);
				}
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1; 
			}
		}
	
	system("PAUSE");	
	return 0;
}
