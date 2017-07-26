#include <stdio.h>
#include "staticlibexports.h"

static int local_function(int x)
{
    printf("sharedLib: %s\n", __FUNCTION__);
    return 0;
}

static int local_function_strippedoff(int x)
{
	printf("sharedLib: %s\n", __FUNCTION__);
	return 0;
}

int shlib_function(void)
{
	printf("sharedLib: %s\n", __FUNCTION__);
	local_function(1);
	local_function_strippedoff(1);
    return 0;
}

