/* circulararea.c:  计算圆形的面积 */
/* 被circle.c的main()调用 */

/* circularArea()函数计算圆形面积
 * 参数:	圆形半径
 * 返回值:	圆形面积 */
double circularArea(double r)			/* circularArea()定义的开始 */
{
	const double pi = 3.1415926536;		/* pi是一个常量 */
	return pi * r * r;
}