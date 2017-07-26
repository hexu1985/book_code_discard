/* Strlen.c */ 
#include <stdio.h>

int strlen(char *s);

int main(int argc, char *argv[])
{
	int len; 
	char s[] = "Hello, I am hexu!";
	
	len = strlen(s);
	printf("the length of \"%s\" is %d\n", s, len);
	
	system("PAUSE");	
	return 0;
}

/* strlen函数：返回字符串s的长度 */
int strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0') 
		p++;
	return p - s;
} 
