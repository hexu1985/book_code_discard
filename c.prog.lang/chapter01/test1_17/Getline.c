/* Getline.c 打印长度大于80个字符的所有输入行 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000	/* maximum input line size */
#define LONGLINE	80

int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	int len;		/* 当前行长度 */
	char line[MAXLINE];		/* 当前的输入行 */
	
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONGLINE)
			printf("%s", line);

	system("PAUSE");	
	return 0;
}

/* getline函数：将一行读入到s中并返回其长度 */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
