/* RENAME.C: This program attempts to rename a file
 * named RENAME.OBJ to RENAME.JBO. For this operation
 * to succeed, a file named RENAMER.OBJ must exist and
 * a file named RENAMER.JBO must not exist.
 */

#include <stdio.h>

void main( void )
{
   int  result;
   char old[] = "RENAME.OBJ", new[] = "RENAME.JBO";

   /* Attempt to rename file: */
   result = rename( old, new );
   if( result != 0 )
      printf( "Could not rename '%s'\n", old );
   else
      printf( "File '%s' renamed to '%s'\n", old, new );
}
