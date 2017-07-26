/* TEMPNAM.C: This program uses tmpnam to create a unique
 * filename in the current working directory, then uses
 * _tempnam to create a unique filename with a prefix of stq.
 */

#include <stdio.h>

void main( void )
{
   char *name1, *name2;

   /* Create a temporary filename for the current working directory: */
   if( ( name1 = tmpnam( NULL ) ) != NULL )
      printf( "%s is safe to use as a temporary file.\n", name1 );
   else
      printf( "Cannot create a unique filename\n" );

   /* Create a temporary filename in temporary directory with the
    * prefix "stq". The actual destination directory may vary
    * depending on the state of the TMP environment variable and
    * the global variable P_tmpdir.
    */
   if( ( name2 = _tempnam( "c:\\tmp", "stq" ) ) != NULL )
      printf( "%s is safe to use as a temporary file.\n", name2 );
   else
      printf( "Cannot create a unique filename\n" );
}


