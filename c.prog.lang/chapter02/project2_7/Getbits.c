/* Getbits.c 函数getbits(x, p, n)返回x中从右边数第p位开始向右数n位的字段。
			 这里假定最右边的一位是第0位，n与p都是合理的正值 */
			 
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
 
int main(int argc, char *argv[])
{
	unsigned x;
	int beg, num; 
	unsigned sub;
	 
	printf("输入一个整数: ");
	scanf("%i", &x);
	printf("输入你想取得的起始位和位数: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("你输入的整数为: %u\n", x); 
	printf("结果为: %u\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits函数：返回x中从地p位开始的n位 */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}
