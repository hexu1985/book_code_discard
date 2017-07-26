// dynamicLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "dynamicLib.h"

// This is an example of an exported variable
int        shlibNonStaticVariable     = 2;
static int shlibStaticVariable 		  = 3;

static int shlib_static_function(int x, int y)
{
	return (x+y)*shlibStaticVariable;
}

int shlib_nonstatic_not_exported_function(int x, int y)
{
	int result = shlib_static_function(x, y);
	return (result*shlibNonStaticVariable);
}

int shlib_nonstatic_exported_function(int x, int y)
{
	int result = 2*shlib_static_function(x, y);
	return (result*shlibNonStaticVariable);
}

DYNAMICLIB_API int shlib_abi_initialize(int x, int y)
{
	int first = shlib_nonstatic_not_exported_function(x, y);
	int second = shlib_nonstatic_exported_function(x, y);
	shlibNonStaticAccessedAsExternVariable = first + second;
	return 0;
}

DYNAMICLIB_API int shlib_abi_uninitialize(void)
{
	shlibNonStaticAccessedAsExternVariable = 0;
	return 0;
}

DYNAMICLIB_API int shlib_abi_reinitialize(int x, int y)
{
	shlib_abi_uninitialize();
	return shlib_abi_initialize(x, y);
}

