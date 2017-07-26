#include <stdio.h>
#include "shlibdemo.h"

int shlib_demo_function(x)
{
	printf("%s()\n", __FUNCTION__);
	return 2*x;
}
