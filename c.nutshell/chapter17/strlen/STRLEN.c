/*  STRLEN.C */

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main( void )
{
   char buffer[61] = "How long am I?";
   int  len;
   len = strlen( buffer );
   printf( "'%s' is %d characters long\n", buffer, len );

   len = sizeof(buffer) / sizeof(char);
   printf( "the length of buffer array is %d\n", len );
}
