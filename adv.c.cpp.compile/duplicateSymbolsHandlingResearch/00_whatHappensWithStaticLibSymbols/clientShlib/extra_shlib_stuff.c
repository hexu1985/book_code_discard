#include <stdio.h>
#include "staticlibexports.h"

int shlib_extra_function(void)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}
