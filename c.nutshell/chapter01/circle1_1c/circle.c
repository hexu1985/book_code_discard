/* circle.c:  计算和输出圆形面积 */

#include <stdio.h>			/* 预处理指令 */

double circularArea(double r);		/* 函数声明 */


int main()				/* main()定义的开始 */
{
	double radius = 1.0, area = 0.0;

	printf("	Areas of Circles\n\n");
	printf("	Radius				Area\n"
		   "----------------------------------------------\n");

	area = circularArea(radius);
	printf("  %10.1f			  %10.2f\n", radius, area);

	radius = 5.0;
	area = circularArea(radius);
	printf("  %10.1f			  %10.2f\n", radius, area);

	putchar('\n');
	return 0;
}

/* circularArea()函数计算圆形面积
 * 参数:	圆形半径
 * 返回值:	圆形面积 */
double circularArea(double r)			/* circularArea()定义的开始 */
{
	const double pi = 3.1415926536;		/* pi是一个常量 */
	return pi * pow(r, 2.0);
}