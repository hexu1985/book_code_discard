/* fast32.c:  具有限定位长的整型类型 */

#include <stdio.h>
#include <stdint.h>

#define ARR_SIZE 100


int main()
{
	int_fast32_t arr[ARR_SIZE];

	int i;
	for ( i = 0; i < ARR_SIZE; ++i ) {
		arr[i] = (int_fast32_t)i;
	}

	for ( i = 0; i < ARR_SIZE; ++i ) {
		if ( i % 5 == 0)
			putchar( '\n' );
		printf( "arr[%d] = %d \t", i, arr[i] );
	}

	putchar( '\n' );
	return 0;
}