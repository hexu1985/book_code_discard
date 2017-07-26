#include <stdio.h>
#include "staticlibexports.h"

using namespace staticlib_original;

int shlib_original_function(void)
{
    int nRetValue = 0;
    nRetValue += staticlib_first_function(1);
    nRetValue += staticlib_second_function(2);
    return nRetValue;
}
