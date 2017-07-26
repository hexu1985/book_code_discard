/* FTELL.C: This program opens a file named FTELL.C
 * for reading and tries to read 100 characters. It
 * then uses ftell to determine the position of the
 * file pointer and displays this position.
 */

#include <stdio.h>

FILE *stream;

void main( void )
{
   long position;
   char list[100];
   if( (stream = fopen( "ftell.c", "rb" )) != NULL )
   {
      /* Move the pointer by reading data: */
      fread( list, sizeof( char ), 100, stream );
	  printf( "%s\n", list );
      /* Get position after read: */
      position = ftell( stream );
      printf( "Position after trying to read 100 bytes: %ld\n",
              position );
      fclose( stream );
   }
}
