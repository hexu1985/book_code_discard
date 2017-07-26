/* GMTIME.C: This program uses gmtime to convert a long-
 * integer representation of coordinated universal time
 * to a structure named newtime, then uses asctime to
 * convert this structure to an output string.
 */

#include <time.h>
#include <stdio.h>

void main( void )
{
   struct tm *newtime;
   long ltime;

   time( &ltime );	// 格林威治标准时间

   /* Obtain coordinated universal time: */
   newtime = gmtime( &ltime );
   printf( "Coordinated universal time is %s\n", 
                               asctime( newtime ) );
}
