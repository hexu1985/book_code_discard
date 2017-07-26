#include <stdlib.h>
#include <stdio.h>
#include "dynamicLib.h"

int main(int argc, const char* argv[])
{
	int t = 0;
	int first, second;

    first = shlibNonStaticAccessedAsExternVariable + 1;
    t = shlib_abi_initialize(first, argc);
    printf("\tThe result of shlib_abi_function_initialize(%d, %d) = %d\n", first, argc, t);

	second = shlibNonStaticAccessedAsExternVariable + 2;
	t = shlib_abi_reinitialize(second, argc);
    printf("\tThe result of shlib_abi_function_reinitialize(%d, %d) = %d\n", second, argc, t);
	
    // Even though is not declared in the library export header, still can be
    // resolved at link time (unless attribute "hidden" is specified).
    // int m = shlib_nonstatic_function(argc, argc); 

    // int p = shlib_static_function(argc, argc);
    getchar();
    return t;
}
