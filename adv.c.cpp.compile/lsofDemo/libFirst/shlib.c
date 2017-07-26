#include <stdio.h>

int shlibfirst_function(int x)
{
    printf("shlibFirst: %s\n", __FUNCTION__);
    return (x+1);
}

