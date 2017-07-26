/* errorexit.c:  ·¶Àýº¯Êýerror_exit() */

#include <stdio.h>
#include "errorexit.h"


int main()
{
	puts( "put the number of error you want to see:\t" );
	int nNumber = 0;
	scanf( "%d", &nNumber );

	printf( "\nthe number you enter is %d\n", nNumber );
	error_exit( nNumber - 1 );

	putchar( '\n' );
	return 0;
}