/* Invert.c 函数invert(x, p, n)将x中从右起第p位(最右边的为第0位)开始的
			n个(二进制)位求反，x的其余位各位保持不变 */
			 
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
unsigned invert(unsigned x, int begbit, int numbits);

int main(int argc, char *argv[])
{
	unsigned x;
	int beg, num; 
	unsigned sub;
	 
	printf("输入一个整数: ");
	scanf("%i", &x);
	printf("输入你想取反的起始位和位数: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("你输入的整数(base 8)为: %o\n", x); 
	printf("取得的位值为: %o\n", sub);
	sub = invert(x, beg, num);
	printf("取反后的值为: %o\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits函数：返回x中从地p位开始的n位 */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* invert: inverts the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p - n + 1));
}
