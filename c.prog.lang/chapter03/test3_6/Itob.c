/* Itoa.c 把数字转换为字符串 */
 
#include <stdio.h>
#include <string.h> 

#define		abs(x)	((x) < 0 ? -(x) : (x)) 

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(int argc, char *argv[])
{
	const int LEN = 11;
	char numstr[LEN]; 
	int n;
	
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("n = [%d]\n", n);
	itoa(n, numstr, 20);
	printf("numstr = [%s]\n", numstr);
	 
	system("PAUSE");	
	return 0;
}

/* itoa: convert n to characters in s, w characters wide - modified */
void itoa(int n, char s[], int w)
{
	int i, sign;
	
	sign = n;		/* record sign */ 
	i = 0;
	do 
		s[i++] = abs(n % 10) + '0';		/* get next digit */
	while ((n /= 10) != 0);		/* delete it */ 
	if (sign < 0) 
		s[i++] = '-';
	while (i < w)
		s[i++] = ' '; 
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

