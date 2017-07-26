#include "shlibexports.h"
#include "secondshlibexports.h"

int shlib_function(void)
{
    int nRetValue = second_shlib_function();
    nRetValue    += nSecondShlibVariable;
    
    // purposefully calling second time
    nRetValue    += second_shlib_function();
    nRetValue    += nSecondShlibVariable;
    return nRetValue;
}
