#include <stdio.h>
#include "staticlibexports.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlib_extra_function(void)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
