#include <stdio.h>
#include "staticlibexports.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlib_function(void)
{
    int nRetValue = 0;
    nRetValue += staticlib_first_function(1);
    nRetValue += staticlib_second_function(2);
    return nRetValue;
}

#ifdef __cplusplus
}
#endif // __cplusplus
