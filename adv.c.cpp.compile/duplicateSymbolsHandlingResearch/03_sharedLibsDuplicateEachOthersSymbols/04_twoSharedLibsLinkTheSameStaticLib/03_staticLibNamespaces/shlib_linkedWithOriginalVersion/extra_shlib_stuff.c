#include <stdio.h>
#include "staticlibexports.h"

int shlib_original_extra_function(void)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int purposefully_identical_function_name(void)
{
	return 2*2*2;
}
