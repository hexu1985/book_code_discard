/* Lower.c 函数lower(c)将ASCII字符集中的字符映射到对应的小写字母 */
 
#include <stdio.h>

int getline(char line[], int maxline); 
int lower(int c);
int upper(int c); 
 
int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	int i, c;
	 
	printf("请输入一行字符(%d个字符以内)\n", LEN - 1);
	getline(line, LEN);
	printf("你输入的字符串为:\n\t%s", line);
	printf("字符串被全小写化为:\n\t");
	for (i = 0; (c = line[i]) != '\0'; ++i) 
		putchar(lower(c));
	printf("字符串被全大写化为:\n\t");
	for (i = 0; (c = line[i]) != '\0'; ++i)
		putchar(upper(c));
		 
	system("PAUSE");	
	return 0;
}

int getline(char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
 
/* lower函数：把字符c转换为小写形式；只对ASCII字符集有效 */
int lower(int c) 
{
	return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}  

/* upper函数：把字符c转换为大写形式；只对ASCII字符集有效 */
int upper(int c) 
{
	return c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c;
} 
