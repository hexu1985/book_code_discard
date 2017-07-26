/* main.c */

#include <stdio.h>
#include <ctype.h>

int main()		/* lower函数：将输入转换为小写形式 */
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}
