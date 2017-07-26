#include <math.h>
#include <setjmp.h>
#include <errno.h>

extern jmp_buf jmp_dest;

double calculate1(double x)
{
	if (x < 0)
		longjmp(jmp_dest, EDOM);
	else
		return sqrt(x);
}

double calculate2(double x)
{
	double y = exp(x);
	if ( y == HUGE_VAL)
		longjmp(jmp_dest, ERANGE);
	else
		return y;
}