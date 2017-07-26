/* Itoa.c 把数字转换为字符串 */
 
#include <stdio.h>
#include <string.h> 

#define		abs(x)	((x) < 0 ? -(x) : (x)) 
void itoa(int num, char *str);
void reverse(char *str);

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

/* itoa: convert n to characters in s; pointer version */
void itoa(int n, char *s)
{
	int sign;		
	char *t = s; 	/* save pointer to s */
	
	sign = n;		/* record sign */ 
	do 
		*s++ = abs(n % 10) + '0';		/* get next digit */
	while ((n /= 10) != 0);		/* delete it */ 
	if (sign < 0) 
		*s++ = '-';
	*s = '\0';
	reverse(t);
}
 
/* reverse: reverse sring s */
void reverse(char *s)
{
	int c;
	char *t; 
	
	for (t = s + (strlen(s) - 1); s < t; s++, t--)
	{
		c = *s;
		*s = *t;
		*t = c;
	} 
}
