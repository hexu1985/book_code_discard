/* Detab.c 将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符
		   终止的地方 */
		    
#include <stdio.h>
#include <stdlib.h>

#define TABINC		8		/* number of blanks necessary */

/* replace tabs with the proper number of blanks */
int main(int argc, char *argv[])
{
	int c, nb, pos;
	
	nb = 0;			/* number of blanks necessary */
	pos = 1;		/* position of character in line */
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')		/* tab character */
		{
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0)
			{
				putchar(' ');
				++pos;
				--nb;
			}
		}
		else if (c == '\n')		/* newline charcter */
		{
			putchar(c);
			pos = 1;
		}
		else
		{
			putchar(c);
			++pos;
		}
	}
			
	system("PAUSE");	
	return 0;
}
