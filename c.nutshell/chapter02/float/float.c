/* float.c:  浮点数据类型 */

#include <stdio.h>


int main()
{
	float height = 1.234567, width = 2.345678;

	float area_f = height * width;
	double area_d = height * width;

	printf( "area_f = %2.18f, \t area_d = %2.18f", area_f, area_d );

	putchar( '\n' );
	return 0;
}