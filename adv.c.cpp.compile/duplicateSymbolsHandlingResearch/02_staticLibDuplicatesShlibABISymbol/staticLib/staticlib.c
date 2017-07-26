#include <stdio.h>
#include "staticlibexports.h"

int staticlib_first_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+1);
}

int staticlib_second_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+2);
}

int shared_static_duplicate_function(int x)
{
	printf("staticlib: %s\n", __FUNCTION__);
	return 0;
}
