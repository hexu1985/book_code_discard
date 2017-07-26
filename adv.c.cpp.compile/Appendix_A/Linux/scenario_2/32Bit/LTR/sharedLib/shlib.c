#include "shlibexports.h"

#define DO_NOT_EXPORT __attribute__ ((visibility("hidden")))

int        nShlibNonStaticVariable     = 2;
static int nshlibStaticVariable 		  = 3;

static int shlib_static_function(int x, int y)
{
	int retValue = x + y;
	retValue    *= nshlibStaticVariable;
	return retValue;
}

int DO_NOT_EXPORT shlib_nonstatic_hidden_function(int x, int y)
{
	int result = shlib_static_function(x, y);
	return result;
}

int shlib_nonstatic_exported_function(int x, int y)
{
	int result = 2*shlib_static_function(x, y);
	// causes problem when compiled on 64-bit OS
	// Compiler flag -mcmodel=large fixes the problem
	result    *= nShlibNonStaticVariable; 
	return result;
}

int shlib_abi_initialize(int x, int y)
{
	int first = shlib_nonstatic_hidden_function(x, y);
	int second = shlib_nonstatic_exported_function(x, y);
	nShlibExportedVariable = first + second;
	return 0;
}

int shlib_abi_uninitialize(void)
{
	return 0;
}

int shlib_abi_reinitialize(int x, int y)
{
	shlib_abi_uninitialize();
	return shlib_abi_initialize(x, y);
}
