/* Trim.c 函数trim用于删除字符串尾部的空格符、制表符与换行符 */
 
#include <stdio.h>
#include <string.h> 

int trim(char str[]); 
int gettext(char text[], int limit); 

int main(int argc, char *argv[])
{
	const int MAXLEN = 1024;
	char str[MAXLEN];
	
	printf("Enter the string:\n");
	gettext(str, MAXLEN);
	printf("The string you enter is:\n[%s]\n", str);
	trim(str);
	printf("After trim, the stirn is:\n[%s]\n", str);
	
	system("PAUSE");	
	return 0;
}

/* trim函数：删除字符串尾部的空格符、制表符与换行符 */
int trim(char s[])
{
	int n;
	
	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') 
			break;
	s[n+1] = '\0';
	return n;
} 

int gettext(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i; 
} 
