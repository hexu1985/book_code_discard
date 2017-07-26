/* usingvoid.c:  演示void数据类型的用法 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* <stdlib.h>头文件
 * 提供下面的函数原型:
 * void srand( unsigned int seed );
 * int rand( void );
 * void* malloc( size_t size );
 * void free( void* ptr );
 * void exit( int status );
 */

enum { ARR_LEN = 100 };


int main()
{
#ifdef TESTCODE
	int i;
	int* pNumbers = malloc( ARR_LEN * sizeof(int) );
#else
	int i,			/* 获得相同的存储空间 */
		*pNumbers = malloc( ARR_LEN * sizeof(int) );
#endif

	if ( pNumbers == NULL ) {
		fprintf( stderr, "Insufficient memory.\n" );
		exit(1);
	}

	srand( (unsigned)time(NULL) );		/* 初始化此随机数产生器 */

	for ( i = 0; i < ARR_LEN; ++i )
		pNumbers[i] = rand() % 10000;	/* 存储某些随机数 */

	printf( "\n%d random numbers between 0 and 9999:\n", ARR_LEN );
	for ( i = 0; i < ARR_LEN; ++i ) {	/* 循环输出 */
		printf( "%6d", pNumbers[i] );	/* 每次循环输出一个数字 */
		if ( i % 10 == 9 )				/* 每十次循环输出一次换行字符 */
			putchar( '\n' );
	}
	free( pNumbers );		/* 释放存储空间 */

	putchar( '\n' );
	return 0;


}