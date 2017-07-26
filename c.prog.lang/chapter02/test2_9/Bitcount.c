/* Bitcount.c 函数bitcount统计其整型参数的值为1的二进制位的个数 */ 

#include <stdio.h>

int bitcount(unsigned x); 

int main(int argc, char *argv[])
{
	unsigned x, n; 
	 
	printf("请输入一个整数: ");
	scanf("%i", &x);
	n = bitcount(x); 
	printf("%x(base 16)中为1的位数(base 2)为%d\n", x, n);
	
	system("PAUSE");	
	return 0;
}

/* bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x !=0; x &= x - 1)
		b++;
	return b;
} 
