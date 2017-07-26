/* Atof.c 把字符串转换为双精度浮点数 */
 
#include <stdio.h>
#include <ctype.h> 

#define MAXLINE 100
 
double atof(char s[]);
int getline(char line[], int max); 

/* 简单计算器程序 */ 
int main(int argc, char *argv[])
{
	double sum, tmp;
	char line[MAXLINE]; 
	
	sum = 0.0; 
	while (getline(line, MAXLINE) > 0)
	{
		printf("line = [%s]\n", line);
		tmp = atof(line);
		printf("tmp = [%7.2lf]\n", tmp); 
		sum += atof(line); 
		printf("\t%lf\n", sum);
	}
		
	system("PAUSE");	
	return 0;
}

/* atof函数：把字符串s转换为相应的双精度浮点数 */
double atof(char s[])
{
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++)		/* 跳过空白 */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) 
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
} 

/* getline函数：将行保存到s中，并返回该行的长度 */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
/*	if (c == '\n') 
		s[i++] = c;*/
	s[i] = '\0';
	return i;
}
