/* STRCMP.C */

#include <string.h>
#include <stdio.h>

char string1[] = "The quick brown dog jumps over the lazy fox";
char string2[] = "The QUICK brown dog jumps over the lazy fox";

void main( void )
{
   char tmp[20];
   int result;
   /* Case sensitive */
   printf( "Compare strings:\n\t%s\n\t%s\n\n", string1, string2 );
   result = strcmp( string1, string2 );
   if( result > 0 )
      strcpy( tmp, "greater than" );
   else if( result < 0 )
      strcpy( tmp, "less than" );
   else
      strcpy( tmp, "equal to" );
   printf( "\tstrcmp:   String 1 is %s string 2\n", tmp );
   /* Case insensitive (could use equivalent _stricmp) */
   result = _stricmp( string1, string2 );
   if( result > 0 )
      strcpy( tmp, "greater than" );
   else if( result < 0 )
      strcpy( tmp, "less than" );
   else
      strcpy( tmp, "equal to" );
   printf( "\t_stricmp:  String 1 is %s string 2\n", tmp );
}


