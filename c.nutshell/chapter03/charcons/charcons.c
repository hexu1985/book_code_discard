/* charcons.c:  ×Ö·û³£Á¿ */

#include <stdio.h>


int main()
{
	int c =0;

	puts( "Please enter a number between 1 and 5:" );

	c = getchar();
	if ( c != EOF && c > '0' && c < '6' ) {
		printf( "\nThe number you entered is %c\n", c );
	} 
	else {
		puts( "\na wrong enter!\n" );
	}

	putchar( '\n' );
	return 0;
}