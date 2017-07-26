/* overflow.c:  上溢出的情况 */

#include <stdio.h>
#include <limits.h>


int main()
{
	unsigned int ui = UINT_MAX;
	printf( "the max value of int type, ui= %u \n", ui );

	ui += 2;
	printf( "overflow, ui = %u \n", ui );

	printf( "\n" );
	return 0;
}