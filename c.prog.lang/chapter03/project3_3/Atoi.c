/* Atoi.c 将字符串转换为对应数值 */
 
#include <stdio.h>
#include <ctype.h> 

int atoi(char str[]); 

int main(int argc, char *argv[])
{
	const int LEN = 11;
	int num;
	char str[LEN];
	
	printf("输入一个整数： ");
	scanf("%s", str);
	num = atoi(str); 
	printf("\nstr = %s, and num = %d\n", str, num);
	
	system("PAUSE");	
	return 0;
}

/* atoi函数：将s转换为整型数；版本2 */
int atoi(char s[]) 
{
	int i, n, sign;
	
	for (i = 0; isspace(s[i]); i++)		/* 跳过空白符 */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') 	/* 跳过符号 */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
 

 
