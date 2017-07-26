/* Strlen.c strlen(s)函数可以返回字符串参数s的长度，但长度不包括
			末尾的'\0' */
			
#include <stdio.h>

int strlen(char *str);
int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	const int LEN = 21;
	char str[LEN];
	int len; 
	 
	printf("输入一个字符串（20的字符以内）\n");
	getline(str, LEN); 
	len = strlen(str);
	printf("\n%s的长度为%d\n", str, len);
	
	system("PAUSE");	
	return 0;
}

/* strlen函数：返回s的长度 */ 
int strlen(char *s)
{
	int n;
	
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
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
