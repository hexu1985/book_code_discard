#include <stdio.h>
#include <dlfcn.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlib_function();    // duplicate ABI function
    shlibfirst_function();
    
    void* pShlibSecond = dlopen("../shlibSecond/libsecond.so", RTLD_GLOBAL | RTLD_NOW);
    if(NULL == pShlibSecond)
    {
		printf("%s\n", dlerror());
		return -1;
	}
	
	SHLIB_FUNCTION pShlibFunction = dlsym(pShlibSecond, "shlib_function");
	if(NULL == pShlibFunction)
	{
		printf("%s\n", dlerror());
	}
	else
	    pShlibFunction();
	
	dlclose(pShlibSecond);
	pShlibSecond = NULL;
	
    return 0;
}
