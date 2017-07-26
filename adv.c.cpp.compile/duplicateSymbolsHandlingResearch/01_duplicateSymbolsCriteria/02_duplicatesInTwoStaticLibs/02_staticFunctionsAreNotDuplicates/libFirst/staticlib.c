#include <stdio.h>

static int local_staticlib_duplicate_function(int x)
{
    printf("libfirst: %s\n", __FUNCTION__);
    return 0;	
}

int staticlibfirst_function(int x)
{
    printf("%s\n", __FUNCTION__);
    local_staticlib_duplicate_function(x);
    return (x+1);
}
