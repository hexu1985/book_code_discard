/* pfun.c:  函数指针的用途 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Add( double x, double y )
{
	return x + y;
}

double Sub( double x, double y )
{
	return x - y;
}

double Mul( double x, double y )
{
	return x * y;
}

double Div( double x, double y )
{
	return x / y;
}

/* 五个"函数指针"的数组，这些函数需要两个double参数，且返回值也是double */
double (*funcTable[5])( double, double ) = { Add, Sub, Mul, Div, pow };

/* "字符串指针"的数组，这些字符串是要输出的 */
char *msgTable[5] = { "Sum", "Difference", "Product", "Quotient", "Power" };


int main()
{
	int i;			/* 一个索引变量 */
	double x = 0, y = 0;

	printf( "Enter two operands for some arithmetic:\n" );
	if ( scanf( "%lf %lf", &x, &y ) != 2 )
		printf( "Invalid input.\n" );

	for ( i = 0; i < 5; ++i )
		printf( "%10s: %6.2f\n", msgTable[i], funcTable[i]( x, y ) );

	return 0;
}