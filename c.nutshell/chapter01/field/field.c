/* field.c:  标识符的作用域 */

#include <stdio.h>

double x;
long calc( double x );


int main()
{
	long x = calc( 2.5 );

	if ( x < 0 ) {
		float x = 2.0F;
		printf( "x in if() is %g \n", x );
	}

	x *= 2;
	printf( "x out if() is %g \n", x );

	return 0;
}

long calc( double x )
{
	long y = (long)x - 5;
	return y;
}