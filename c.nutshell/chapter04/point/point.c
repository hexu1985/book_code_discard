/* point.c:  数组指针的修饰符 */

#include <stdio.h>


int main()
{
	int* iPtr = 0;		/* 指向int的指针，初始化为0 */
	int iArray[] = { -10, 0, 10, 20 };		/* 初始化一个int数组 */

	int array_length = sizeof(iArray) / sizeof(int);	/* 获取元素的个数 */

	printf( "The array starts at the address %p.\n", iArray );
	*iArray = 5;			/* 等于iArray[0] = 5; */

	iPtr = iArray + array_length - 1;	/* 指向iArray最后的元素，
										 * 相当于:
										 * iPtr = &iArray[array_length - 1];
										 */

	printf( "The last element of the array is %d.\n", *iPtr );

	return 0;
}