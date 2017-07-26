/* Any.c 函数any(s1, s2)将字符串s2中的任一字符在字符串s1中第一次出现的位置
		 作为结果返回 */
		 
#include <stdio.h>

int getline(char line[], int maxsize, int delim);
int any(char sour[], char sear[]);
 
int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	char search[LEN]; 
	int pos; 
	
	printf("请输入一行字符串(在%d个字符以内)\n", LEN - 1);
	getline(line, LEN, '#');
	printf("请输入你想匹配的的字符集: ");
	getline(search, LEN, '#');
	pos = any(line, search);
	printf("第一个匹配字符的位置为: %d\n", pos);	
		
	system("PAUSE");	
	return 0;
}

/* getline函数：将一行读入到s中并返回其长度，lim为s的长度包括'\0', 
				end为结束符 */
int getline(char s[], int lim, int end)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != end; ++i)
		s[i] = c;
	s[i] = '\0';
	
	return i;
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])		/* match found? */
				return i;			/* location first match */

	return -1; 		/* otherwise, no match */
} 
