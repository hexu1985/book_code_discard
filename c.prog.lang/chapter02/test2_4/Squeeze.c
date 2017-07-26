/* Squeeze.c 函数squeeze(s1, s2)将字符串s1中任何与字符串s2中字符匹配的字符串
			 删除 */
 
#include <stdio.h>

int getline(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	char str[LEN];		 
	
	printf("请输入一行字符串(在%d个字符以内)\n", LEN - 1);
	getline(line, LEN);
	printf("请输入你想删除的字符集(在%d个字符以内): ", LEN - 1);
	getline(str, LEN);
	printf("原字符串为: \n\t%s\n", line);
	printf("你想删除的字符集为: %s\n", str);
	squeeze(line, str);
	printf("\n删除后的字符串为: \n\t%s\n", line);
	
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

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[]) 
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++) 
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')		/* end of string - no match */
			s1[k++] = s1[i];
	}
	
	s1[k] = '\0';
} 
	 
