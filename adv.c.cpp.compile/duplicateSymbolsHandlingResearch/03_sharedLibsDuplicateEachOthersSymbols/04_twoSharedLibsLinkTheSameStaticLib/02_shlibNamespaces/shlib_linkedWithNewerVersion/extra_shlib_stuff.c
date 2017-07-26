#include <stdio.h>
#include "staticlibexports.h"


namespace shlib_newer
{
	
int shlib_newer_extra_function(void)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int purposefully_identical_function_name(void)
{
	return 7*7*7;
}

}; // namespace shlib_newer

