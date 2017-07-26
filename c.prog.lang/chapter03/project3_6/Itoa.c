/* Itoa.c 把数字转换为字符串 */
 
#include <stdio.h>
#include <string.h> 

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[])
{
	const int LEN = 11;
	char numstr[LEN]; 
	int n;
	
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("n = [%d]\n", n);
	itoa(n, numstr);
	printf("numstr = [%s]\n", numstr);
	 
	system("PAUSE");	
	return 0;
}

/* itoa函数：将数字n转换为字符串并保存到s中 */
void itoa(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0) 	/* 记录符号 */
		n = -n;			/* 使n成为正数 */
	i = 0;
	do 							/* 以反序生成数字 */ 
		s[i++] = n % 10 + '0';		/* 取下一个数字 */
	while ((n /= 10) > 0);		/* 删除该数字 */ 
	if (sign < 0) 
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
 
/* reverse: reverse sring s */
void reverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	} 
}
