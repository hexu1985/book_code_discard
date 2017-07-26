#include <stdio.h>
#include "staticlibexports.h"

static int local_function(int x)
{
    printf("staticLib: %s\n", __FUNCTION__);
    return 0;	
}

int staticlib_function(int x)
{
    printf("%s\n", __FUNCTION__);
    local_function(x);
    return (x+1);
}

