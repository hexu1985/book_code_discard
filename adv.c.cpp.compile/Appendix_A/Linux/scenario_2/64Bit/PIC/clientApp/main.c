#include <stdio.h>
#include "shlibexports.h"

extern  int shlibAccessedAsExternVariable;

int main(int argc, const char* argv[])
{
    int t;
    int first = nShlibExportedVariable + 1;
    t = shlib_abi_initialize(first, argc);

    int second = nShlibExportedVariable + 2;
    t = shlib_abi_reinitialize(second, argc);
	
    // compiler warns about implicit declaration 
    // of this function, but manages to resolve it
    // at run time. We did not plan on exporting it
    // but also did not bother to explicitly hide it
    t = shlib_nonstatic_exported_function(first, argc);
    
#if 0
    // can't access hidden function
    t = shlib_nonstatic_hidden_function(first, argc);

    // calling these two will result with compiler error    
    int result = shlib_static_function(first, second);
    result    *= shlibNonStaticVariable;
#endif
    return t;
}
