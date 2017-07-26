#include "shlibexports.h"
#include "secondshlibexports.h"

int shlib_function(void)
{
	int nRetValue = second_shlib_function();
	
	// purposefully calling second time
	nRetValue    += second_shlib_function();
    return nRetValue;
}
