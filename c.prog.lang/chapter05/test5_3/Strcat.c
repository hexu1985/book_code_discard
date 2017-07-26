/* Strcat.c 函数strcat(s, t)将字符串t连接到字符串s的尾部 */
 
#include <stdio.h>

int getline(char line[], int maxlen); 
void strcat(char *dest, char *sour);
 
int main(int argc, char *argv[])
{
	const int LEN1 = 51, LEN2 = 26;
	char str1[LEN1], str2[LEN2];
	printf("请输入第一行字符(25个字符以内):\n");
	getline(str1, LEN2);
	printf("请输入第二行字符(25个字符以内):\n"); 
	getline(str2, LEN2);
	printf("你输入第一行字符为:\nstr1 = [%s]", str1);
	printf("你输入第二行字符为:\nstr2 = [%s]", str2);
	printf("下面将str2连接到str1后\n");
	strcat(str1, str2);
	printf("连接后的str1为:\nstr1 = [%s]", str1);
	
	system("PAUSE");	
	return 0;
}

/* getline函数：将一行读入到s中并返回其长度 ，lim为s的长度包括'\0' */
int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
/*	if (c == '\n') 
		s[i++] = c;	*/
	s[i] = '\0';
	
	return i;
} 

/* strcat: concatenate t to the end of s; pointer version */ 
void strcat(char *s, char *t)
{
	while(*s)
		s++;
	while (*s++ = *t++)
		; 
} 
