#include <stdio.h>

int shlibsecond_function(int x)
{
    printf("shlibSecond: %s\n", __FUNCTION__);
    return (x+1);
}
