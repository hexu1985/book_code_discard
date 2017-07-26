#include <stdafx.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlib_function();    // duplicate ABI function
    shlibfirst_function();
    
    HMODULE hShlibSecond = LoadLibrary(L"libsecond.dll");
    if(NULL == hShlibSecond)
    {
		printf("Failed loading libsecond.dll\n");
		return -1;
	}
	
	SHLIB_FUNCTION pShlibFunction = (SHLIB_FUNCTION)GetProcAddress(hShlibSecond, "shlib_function");
	if(NULL == pShlibFunction)
	{
		printf("Failed retrieving shlib_function symbol\n");
	}
	else
	    pShlibFunction();
	
	FreeLibrary(hShlibSecond);
	hShlibSecond = NULL;
	
    return 0;
}
