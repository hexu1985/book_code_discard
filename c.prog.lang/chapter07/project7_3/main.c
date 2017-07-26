/* main.c */

#include <stdio.h>

int main()	/* ¼òµ¥¼ÆËãÆ÷³ÌĞò */
{
	double sum, v;
	
	sum = 0;
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum += v);
	return 0;
}