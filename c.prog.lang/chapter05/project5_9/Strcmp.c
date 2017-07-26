/* Strcmp.c */
 
#include <stdio.h>

#define LEN		128
 
int strcmp(char *str1, char *str2);
int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	char response;
	char str1[LEN], str2[LEN];
	int result; 
	
	do
	{ 
		printf("输入第一个字符串(小于128个字符), 以回车结束\n");
		getline(str1, LEN);
		printf ("输入第二个字符串(小于128个字符), 以回车结束\n");
		getline(str2, LEN);
		
		result = strcmp(str1, str2);
		if (result == 0)
			printf("第一个字符串等于第二个字符串.\n");
		else if (result > 0)
			printf("第一个字符串大于第二个字符串.\n");
		else
			printf("第一个字符串小于第二个字符串.\n"); 
		
		printf("继续吗? (y/n): ");
		result = getchar();
		while(getchar() != '\n')
			; 
	} 
	while (result != 'n' && result != 'N');
	
	system("PAUSE");	
	return 0;
}

/* strcmp函数：根据s按照字典顺序小于、等于或大于t的结果分别返回负整数、0
			   或正整数 */
int strcmp(char *s, char *t) 
{
	int i;
	
	for (i = 0; s[i] == t[i]; i++) 
		if (s[i] == '\0') 
			return 0;
	return s[i] - t[i];
} 

/* getline函数：将一行读入到s中并返回其长度 */
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
