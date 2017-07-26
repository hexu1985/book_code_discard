/* EXITER.C: This program prompts the user for a yes
 * or no and returns an exit code of 1 if the
 * user answers Y or y; otherwise it returns 0. The
 * error code could be tested in a batch file.
 */

//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int ch;
/*
   _cputs( "Yes or no? " );
   ch = _getch();
   _cputs( "\r\n" );
   if( toupper( ch ) == 'Y' )
      exit( 1 );
   else
      exit( 0 );
*/

   puts( "Yes or no? " );
   ch = getchar();
   puts( "\r\n" );
   if( toupper( ch ) == 'Y' )
      exit( 1 );
   else
      exit( 0 );
   
}
