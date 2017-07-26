
#include <stdio.h>
#include <math.h>

#define PI			3.141593
#define STEP		(PI/8)
#define AMPLITUDE	1.0
#define ATTENUATION	0.1
#define DF(x)		exp(-ATTENUATION*(x))
#define FUNC(x)		(DF(x) * AMPLITUDE * cos(x))
#define STR(s)		#s
#define XSTR(s)		STR(s)


int main()
{
	double x = 0.0;

	printf( "\nFUNC(x) = %s\n", XSTR(FUNC(x)) );

	printf( "\n %10s %25s\n", "x", STR(y = FUNC(x)) );
	printf( "-----------------------------------------\n" );
	for ( ; x < 2 * PI + STEP / 2; x += STEP )
		printf( "%15f %20f\n", x, FUNC(x) );

	return 0;
}