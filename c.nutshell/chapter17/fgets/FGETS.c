/* FGETS.C: This program uses fgets to display
 * a line from a file on the screen.
 */

#include <stdio.h>

void main( void )
{
   FILE *stream;
   char line[100];

   if( (stream = fopen( "fgets.c", "r" )) != NULL )
   {
      if( fgets( line, 100, stream ) == NULL)
         printf( "fgets error\n" );
      else
         printf( "%s", line);
      fclose( stream );
   }
}


