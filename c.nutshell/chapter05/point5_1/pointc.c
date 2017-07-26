/* pointc.c:  指针的运算操作 */

#include <stdio.h>


int main()
{
	double dArr[5] = { 0.0, 1.1, 2.2, 3.3, 4.4 };	/* 初始化一个数组 */
	double* dPtr = dArr;		/* 初始化一个指针，指向数组的第一个元素 */

	int i = 0;		/* 一个索引变量 */

	dPtr = dPtr + 1;	/* 让dPtr前进到第二个元素 */
	dPtr = 2 + dPtr;	/* 整数也可以写在加法的前面，现在dPtr指向dArr[3] */

	printf( "%.1f\n", *dPtr );	/* 输出dPtr所引用的元素 */
	printf( "%.1f\n", *(dPtr - 1) );	/* 输出当前位置之前的元素，且没有修改dPtr指针 */

	i = dPtr - dArr;		/* 结果：数组元素的索引 */
	printf( "当前元素索引i = %d\n", i );

	printf( "\n" );
	return 0;
}