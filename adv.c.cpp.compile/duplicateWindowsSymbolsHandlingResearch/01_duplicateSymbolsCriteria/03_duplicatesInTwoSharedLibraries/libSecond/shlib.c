#include <stdio.h>

static int local_shlib_duplicate_function(int x)
{
    printf("shlibSecond: %s\n", __FUNCTION__);
    return 0;	
}

int shlibsecond_function(int x)
{
    printf("shlibSecond: %s\n", __FUNCTION__);
    local_shlib_duplicate_function(x);
    return (x+1);
}

int shlib_duplicate_function(int x)
{
    printf("shlibSecond: %s\n", __FUNCTION__);
    local_shlib_duplicate_function(x);
    return (x+2);
}
