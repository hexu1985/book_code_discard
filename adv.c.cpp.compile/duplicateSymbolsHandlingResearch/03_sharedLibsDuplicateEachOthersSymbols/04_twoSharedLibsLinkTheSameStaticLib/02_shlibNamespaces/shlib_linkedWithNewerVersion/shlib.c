#include <stdio.h>
#include "staticlibexports.h"

namespace shlib_newer
{
	
int shlib_newer_function(void)
{
    int nRetValue = 0;
    nRetValue += staticlib_first_function(1);
    nRetValue += staticlib_second_function(2);
    return nRetValue;
}

}; // namespace shlib_newer
