/* ASINCOS.C: This program prompts for a value in the range
 * -1 to 1. Input values outside this range will produce
 * _DOMAIN error messages.If a valid value is entered, the
 * program prints the arcsine and the arccosine of that value.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define PI 3.141593
#define DEG_PER_RAD (180.0/PI)

void main( void )
{
   double x, y;

   printf( "Enter a real number between -1 and 1: " );
   scanf( "%lf", &x );
   y = asin( x );
   y *= DEG_PER_RAD;
   printf( "Arcsine of %f = %f\n", x, y );
   y = acos( x );
   y *= DEG_PER_RAD;
   printf( "Arccosine of %f = %f\n", x, y );
}
