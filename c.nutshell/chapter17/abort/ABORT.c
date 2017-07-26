/* ABORT.C:  This program tries to open a
 * file and aborts if the attempt fails.
 */

#include  <stdio.h>
#include  <stdlib.h>

void main( void )
{
   FILE *stream;

   if( (stream = fopen( "NOSUCHF.ILE", "r" )) == NULL )
   {
      perror( "Couldn't open file" );
      abort();
   }
   else
      fclose( stream );
}
