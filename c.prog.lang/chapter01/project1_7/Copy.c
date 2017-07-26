#include <stdio.h>
#include <stdlib.h>

/* 将输入复制到输出；版本1 */ 
int main(int argc, char *argv[])
{
	int c;
	
	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
	 
	system("PAUSE");	
	return 0;
}
