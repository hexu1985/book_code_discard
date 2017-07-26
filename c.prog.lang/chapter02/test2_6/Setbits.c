/* Setbits.c 函数setbits(x, p, n, y)将x中从第p位开始(这里假定右边的一位是第0位)
			 的n个(二进制)位设置为y中最右边n位的值，x的其余各位保持不变，并将
			 结果值返回 */
			  
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
unsigned setbits(unsigned x, int p, int n, unsigned y);
 
int main(int argc, char *argv[])
{
	unsigned x, y;
	int beg, num; 
	unsigned sub;
	 
	printf("输入一个整数: ");
	scanf("%i", &x);
	printf("输入你想取得的起始位和位数: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("你输入的整数(base 8)为: %o\n", x); 
	printf("结果为: %o\n", sub);
	printf("输入你想设置的值: ");
	scanf("%i", &y);
	sub = setbits(x, beg, num, y);
	printf("结果为: %o\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits函数：返回x中从地p位开始的n位 */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* setbits: set n bits of x at position p with bits of y */ 
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p - n + 1)) |
			(y & ~(~0 << n)) << (p - n + 1);
} 
