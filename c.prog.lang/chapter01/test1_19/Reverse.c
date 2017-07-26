/* Reverse.c 每次颠倒一个输入行中的字符顺序 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
int main(int argc, char *argv[])
{
	char line[MAXLINE];		/* 当前的输入行 */
	
	while (getline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	
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

/* reverse: reverse sring s */
void reverse(char s[])
{
	int i, j;
	char temp;
	
	i = 0;
	while (s[i] !='\0')		/* find the end of string s */
		++i;
	--i;					/* back off from '\0' */
	if (s[i] == '\n')
		--i;				/* leave newline in place */
	j = 0;					/* beginning of new string s */
	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}
