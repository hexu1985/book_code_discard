#include <stdio.h>

static int shlib_local_function(void)
{
	printf("shlibSecond: %s\n", __FUNCTION__);
	return 0;
}

int shlib_non_static_function(void)
{
	printf("shlibSecond: %s\n", __FUNCTION__);
    shlib_local_function();
    return 0;
}

int shlibsecond_function(void)
{
	printf("%s\n", __FUNCTION__);
	shlib_non_static_function();
	return 0;
}
