/* Word.c 一个以每行一个单词的形式打印其输入的程序 */
 
#include <stdio.h>
#include <stdlib.h>

#define IN	1	/* 在单词内 */
#define OUT	0	/* 在单词外 */

/* print input one word per line */ 
int main(int argc, char *argv[])
{
	int c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF) 
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == IN)
			{
				putchar('\n');		/* finish the word */
				state = OUT;
			}
		}
		else if (state == OUT)		/* beginnig of word */
		{
			state = IN;
			putchar(c);
		}
		else
			putchar(c);				/* inside a word */
	}
  
	system("PAUSE");	
	return 0;
}
