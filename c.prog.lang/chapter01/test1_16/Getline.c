#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* 允许的输入行的最大长度 */

int getline(char line[], int maxline);
void copy(char to[], char from[]); 

int main(int argc, char *argv[])
{
	int len;		/* 当前行长度 */
	int max;		/* 目前为止发现的最长行的长度 */
	char line[MAXLINE];		/* 当前的输入行 */
	char longest[MAXLINE];	/* 用于保存最长的行 */
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		printf("%d, %s", len, line);
		if (len > max)	
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* 存在这样的行 */ 
		printf("%s", longest); 
		
	system("PAUSE");	
	return 0;
}

/* getline函数：将一行读入到s中并返回其长度 */
#ifdef GETLINE_ONE
int getline(char s[], int lim) 
{
	int c, i, j;
	
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) 
		if (i < lim - 2)
		{
			s[j] = c;	/* line still in boundaries */
			++j;
		}
	if (c == '\n')
	{
		s[j] = c;
		++j;
		++i;
	}
	s[i] = '\0';
	return i;
}
#else
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
#endif

/* copy函数：将from复制到to；这里假定to足够大 */
void copy(char to[], char from[]) 
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0') 
		++i; 
}
