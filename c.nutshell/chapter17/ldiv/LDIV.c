/* LDIV.C: This program takes two long integers
 * as command-line arguments and displays the
 * results of the integer division.
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void main( void )
{
   long x = 5149627, y = 234879;
   ldiv_t div_result;

   div_result = ldiv( x, y );
   printf( "For %ld / %ld, the quotient is ", x, y );
   printf( "%ld, and the remainder is %ld\n", 
            div_result.quot, div_result.rem );
}
