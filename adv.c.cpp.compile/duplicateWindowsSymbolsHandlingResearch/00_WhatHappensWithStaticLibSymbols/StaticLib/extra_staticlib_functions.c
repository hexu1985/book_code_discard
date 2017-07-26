#include <stdio.h>
#include "staticlibexports.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int staticlib_third_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+1);
}

int staticlib_fourth_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+2);
}

#ifdef __cplusplus
}
#endif // __cplusplus
