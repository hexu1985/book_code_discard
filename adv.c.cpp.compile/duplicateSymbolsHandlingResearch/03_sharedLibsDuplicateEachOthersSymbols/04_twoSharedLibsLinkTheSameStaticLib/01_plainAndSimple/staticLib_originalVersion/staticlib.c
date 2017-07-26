#include <stdio.h>
#include "staticlibexports.h"

static int staticlib_unexported_static_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+64);
}

int staticlib_unexported_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return staticlib_unexported_static_function(128);
}

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
