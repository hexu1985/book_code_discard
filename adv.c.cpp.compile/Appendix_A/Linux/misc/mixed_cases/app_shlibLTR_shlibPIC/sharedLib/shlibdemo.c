#include "shlibdemo.h"
#include "dependencyShlib.h"

#define DO_NOT_EXPORT __attribute__ ((visibility("hidden")))

int        shlibNonStaticVariable     = 2;
static int shlibStaticVariable 		  = 3;

static int shlib_static_function(int x, int y)
{
	int retValue = x + y;
	retValue    *= shlibStaticVariable;
	return retValue;
}

int DO_NOT_EXPORT shlib_nonstatic_not_exported_function(int x, int y)
{
	int result = shlib_static_function(x, y);
	result    *= shlibNonStaticVariable;
	return result;
}

int shlib_nonstatic_exported_function(int x, int y)
{
	int result = 2*shlib_static_function(x, y);
	result    *= shlibNonStaticVariable;
	return result;
}

int shlib_abi_initialize(int x, int y)
{
	int first = shlib_nonstatic_not_exported_function(x, y);
	int second = shlib_nonstatic_exported_function(x, y);
	shlibNonStaticAccessedAsExternVariable = first + second;
	int nRetValue = dependency_shlib_function(first, second);
	return nRetValue;
}

int shlib_abi_uninitialize(void)
{
	shlibNonStaticAccessedAsExternVariable = 0;
	return 0;
}

int shlib_abi_reinitialize(int x, int y)
{
	shlib_abi_uninitialize();
	return shlib_abi_initialize(x, y);
}
