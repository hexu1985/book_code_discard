/* Squeeze.c 函数squeeze(s, c)删除字符串s中出现的所有字符c */
 
#include <stdio.h>

int getline(char line[], int maxline);
void squeeze(char str[], int c);

int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	int c;
 	/* int c = 0; */	 /* c必须先初始化为0，不然squeeze无法得到你想要的结果 */ 
	
	printf("请输入一行字符串(在%d个字符以内)\n", LEN - 1);
	getline(line, LEN);
	printf("请输入你想删除的字符: ");
	/* scanf("%c", &c); */
	c = getchar();
	printf("原字符串为: \n\t%s\n", line);
	printf("你想删除的字符为: %c\n", c);
	squeeze(line, c);
	printf("\n删除后的字符串为: \n\t%s", line);
	
	system("PAUSE");	
	return 0;
}

/* getline函数：将一行读入到s中并返回其长度 ，lim为s的长度包括'\0' */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 

/* squeeze函数：从字符串中s删除字符c */
void squeeze(char s[], int c) 
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++) 
		if (s[i] != c) 
			s[j++] = s[i];
	
	s[j] = '\0';
} 
	 
