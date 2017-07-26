#include <stdio.h>
#include <stdlib.h>

int power(int m, int n);

/* 测试power函数 */ 
int main(int argc, char *argv[])
{
	int i;
	
	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
		
	system("PAUSE");	
	return 0;
}

/* power函数：求底数的n次幂；其中n >= 0 */
int power(int base, int n)
{
	int i, p;
	
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
 
