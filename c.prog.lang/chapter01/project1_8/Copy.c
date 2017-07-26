#include <stdio.h>
#include <stdlib.h>

/* 将输入复制到输出；版本2 */ 
int main(int argc, char *argv[])
{
	int c;
	
	while ((c = getchar()) != EOF) 
		putchar(c);
		 
	system("PAUSE");	
	return 0;
}
