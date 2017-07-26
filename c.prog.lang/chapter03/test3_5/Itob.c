/* Itob.c 函数itob(n, s, b)将整数n转换为以b为底的数，并将转换结果以字符的形式
		  保存到字符串s中 */
		   
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]); 

int main(int argc, char *argv[])
{
	const int LEN = 11;
	char numstr[LEN]; 
	int n;
	
	printf("Enter an integer: ");
	scanf("%i", &n);
	printf("n = [%x]\n", n);
	itob(n, numstr, 16);
	printf("numstr = [%s]\n", numstr);  
	
	system("PAUSE");	
	return 0;
}

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
	int i, j, sign;
	
	if ((sign = n) < 0) 		/* record sign */
		n = -n;				/* make n positive */
	i = 0;
	do						/* generate digits in reverse */ 
	{
		j = n % b;			/* get next digit */ 
		s[i++] = (j <= 9) ? j + '0' : j - 10 + 'a';
	}
	while ((n /= b) >0);		/* delete it */ 
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
