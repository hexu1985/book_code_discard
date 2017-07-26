/* Change.c 一个将输入复制到输出的程序，并将其中的制表符替换为\t，把回退符
			替换为\b，把反斜杠替换为\\ */
						 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;

#ifdef STYLE_ONE	
	while ((c = getchar())!= EOF)
	{
		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
		if (c != '\b')
			if (c != '\t')
				if (c != '\\')
					putchar(c);
	}
#else
	while ((c = getchar()) != EOF)
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
#endif

	system("PAUSE");	
	return 0;
}
