/* SQRT.C: This program calculates a square root. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   double question = 45.35, answer;

   answer = sqrt( question );
   if( question < 0 )
      printf( "Error: sqrt returns %.2f\n, answer" );
   else
      printf( "The square root of %.2f is %.2f\n", question, answer );
}
