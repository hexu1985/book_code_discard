#include <stdio.h>
#include <complex.h>

int main()
{
	double complex z[4];
	z[0] = 3.0 + 4.0 * I;
	z[1] = conj( z[0] );
	z[2] = z[0] * I;
	z[3] = -( z[0] );

	int i = 0;
	for ( i = 0; i < 4; i++ )
	{
		double a = creal( z[i] );
		double b = cimage( z[i] );
		printf( "The absolute value of (%4.2f %+4.2f * I) is ", a, b );

		double absolute_z = cabs( z[i] );
		printf( "%4.2f.\n", absolute_z );
	}

	return 0;
}