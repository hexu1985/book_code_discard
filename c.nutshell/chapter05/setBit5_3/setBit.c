/* setBit.c:  使用位移操作处理位掩码 */

#include <stdio.h>
#include <limits.h>

/* setBit()函数
 * 将屏蔽m的p位置，设置为1
 * 使用CHAR_BIT(定义在limits.h中)储存一个字节内的位数目
 * 返回值：返回新的位掩码，其中位p已经设置好；如果p是无效的位置，则返回原始位掩码
 */
unsigned int setBit( unsigned int mask, unsigned int p )
{
	if ( p >= CHAR_BIT * sizeof(int) ) 
		return mask;
	else
		return mask | ( 1 << p );
}

/* printBit()函数
 * 将intBit按二进制数输出
 */
void printBit( unsigned int intBit )
{
	const int arrlen = CHAR_BIT * sizeof(int);

	int i;
	int singleBit;
	for ( i = arrlen - 1; i >= 0; --i ) {
		singleBit = 0;
		singleBit = 0x01 & ( intBit >> i );
		printf( "%d", singleBit );
	}

	printf( "\n" );
}


int main()
{
	unsigned int testmask = 11;
	unsigned int bitset = 7;

	printf( "the testmask is:\n" );
	printBit( testmask );

	testmask = setBit( testmask, bitset );

	printf( "the 7 bit is set, testmask now is:\n" );
	printBit( testmask );

	printf( "\n" );
	return 0;
}