/* DIFFTIME.C: This program calculates the amount of time
 * needed to do a floating-point multiply 10 million times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main( void )
{
   time_t   start, finish;
   long loop;
   double   result, elapsed_time;

   printf( "Multiplying 2 floating point numbers 1 billion times...\n" );
   
   time( &start );
   for( loop = 0; loop < 1000000000; loop++ )
      result = 3.63 * 5.27; 
   time( &finish );

   elapsed_time = difftime( finish, start );
   printf( "\nProgram takes %6.0f seconds.\n", elapsed_time );
}
