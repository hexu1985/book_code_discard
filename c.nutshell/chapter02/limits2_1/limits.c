/* limits.c:  显示char和int类型的值范围 */

#include <stdio.h>
#include <limits.h>


int main()
{
	printf( "Storage sizes and value ranges of the types char and int\n\n" );
	printf( "The type char is %s.\n\n", CHAR_MIN < 0 ? "signed" : "unsigned" );

	printf( "Type    Size(in bytes)      Minimum          Maximum\n"
			"----------------------------------------------------\n" );
	printf( " char %8d %20d %15d\n", sizeof( char ), CHAR_MIN, CHAR_MAX );
	printf( " int  %8d %20d %15d\n", sizeof( int ), INT_MIN, INT_MAX );

	return 0;
}