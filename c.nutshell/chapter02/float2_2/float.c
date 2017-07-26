/* float.c:  展示float数据类型的精确度 */

#include <stdio.h>
#include <float.h>


int main()
{
	puts( "\nCharacteristics of the type float\n" );

	printf( "Storage size: %d bytes\n"
		    "Smallest positive value: %E\n"
		    "Greatest positive value: %E\n"
		    "Precision: %d decimal digits\n",
		    sizeof(float), FLT_MIN, FLT_MAX, FLT_DIG );

	puts( "\nAn example of float precision:\n" );

	double d_var = 12345.6;			/* double数据类型的变量 */
	float f_var = (float)d_var;		/* 使用d_var的值，初始化此float变量 */

	printf( "The floatint-point number    "
			"%18.10f\n", d_var );
	printf( "has been stored in a variable\n"
			"of type float as the value    " 
			"%18.10f\n", f_var );
	printf( "the rounding error is         " 
			"%18.10f\n", d_var - f_var );

	putchar( '\n' );
	return 0;
}