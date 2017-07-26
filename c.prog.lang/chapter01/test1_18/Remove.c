/* Remove.c 删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
int Remove(char s[]);

int main(int argc, char *argv[])
{
	char line[MAXLINE];		/* 当前的输入行 */
	
	while (getline(line, MAXLINE) > 0)
		if (Remove(line) > 0)
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

/* Remove trailing blanks and tabs from character string s */
int Remove(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != '\n')	/* find newline character */
		++i;
	--i;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0)				/* is it a nonblank line? */
	{
		++i;
		s[i] = '\n';		/* put newline character back */
		++i;
		s[i] = '\0';
	}
	return i;
}

