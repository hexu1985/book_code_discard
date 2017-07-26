/* EXP.C */

#include <math.h>
#include <stdio.h>

void main( void )
{
   double x = 2.302585093, y;

   y = exp( x );
   printf( "exp( %f ) = %f\n", x, y );
}
