#include <stdio.h>

static int shlib_function(void)
{
	printf("shlibSecond: %s\n", __FUNCTION__);
	return 0;
}

int shlibsecond_function(void)
{
	printf("%s\n", __FUNCTION__);
	shlib_function();
	return 0;
}
