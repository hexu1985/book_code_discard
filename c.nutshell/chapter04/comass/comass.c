/* comass.c:  在复合赋值语句(compound assignment)中的隐式的类型转换 */

#include <stdio.h>
#include <math.h>


int main()
{
	int i = 7;
	float x = 0.5;
	printf( "i = %d, x = %f\n", i, x );

	i = x;
	printf( "after \"i = x\", i = %d, x = %f\n", i, x );

	x += 2.5;
	printf( "after \"x += 2.5\", x = %f\n", x );

	x = sqrt( i );
	printf( "after \"x = sqrt( 1 )\", x = %f\n", x );

	printf( "\n" );
	return 0;
}