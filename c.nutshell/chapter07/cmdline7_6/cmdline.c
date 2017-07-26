/* cmdline.c:  ÃüÁîĞĞ */

#include <stdio.h>


int main( int argc, char* argv[] )
{
	if ( argc == 0 )
		puts( "No command line available." );
	else {
		printf( "The program now running: %s\n", argv[0] );
		if ( argc == 1 )
			puts( "No arguments received on the command line." );
		else {
			puts( "the command line arguments:" );
			for ( int i = 1; i < argc; ++i )
				puts( argv[i] );
		}
	}
	
	putchar( '\n' );
	return 0;
}