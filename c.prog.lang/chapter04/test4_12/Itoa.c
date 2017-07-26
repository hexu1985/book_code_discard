/* Itoa.c 把数字转换为字符串 */
 
#include <stdio.h>
#include <string.h> 

#define		abs(x)	((x) < 0 ? -(x) : (x)) 
void itoa(int n, char s[]);

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

/* itoa: convert n to characters in s - recursive */
void itoa(int n, char s[])
{
	static int i;
	
	if (n / 10)
		itoa(n / 10, s);
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';	
}

