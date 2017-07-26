/* Strindex.c 函数strindex(s, t)返回字符串t在s中最左边出现的位置，如果s中
			  不包含t，则返回-1 */
 
#include <stdio.h>

#define		MAXLINE		1000	/* 最大输入行长度 */

int getline(char *line, int lim);
int strindex(char *source, char *searchfor);

char pattern[] = "ould";		/* 待查找的模式 */ 
 
/* 找出所有与模式匹配的行 */ 
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line, MAXLINE) > 0) 
		if (strindex(line, pattern) >= 0) 
		{
			printf("%s", line);
			found++;
		}
	 
	system("PAUSE");	
	return found;
}

/* strindex函数：返回t在s中的位置(数组下标)，若未找到则返回-1 */
int strindex(char *s, char *t) 
{
	char *b = s;			/* beginning of string s */
	char *p, *r;
	
	for ( ; *s != '\0'; s++)
	{
		for ( p = s, r = t; *r != '\0' && *p == *r; p++, r++)
			;
		if (r > t && *r == '\0') 
			return s - b;
	}
	return -1;
} 

/* getline函数：将行保存到s中，并返回该行的长度 */
int getline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n') 
		*s++ = c;
	*s = '\0';
	return s - t;
}
