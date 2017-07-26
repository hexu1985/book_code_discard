#include <stdio.h>
#include "shliboriginalexports.h"
#include "shlibnewerexports.h"

int main(int argc, char* argv[])
{
    int nOriginal = shlib_original_function();
    printf(" app: shlib_original_function() = %d\n", nOriginal);
    int nNewer    = shlib_newer_function();
    printf(" app: shlib_newer_function()    = %d\n", nNewer);

#if 0 // if duplicate symbols is part of ABI, the linker will cry foul !!!    
    return purposefully_duplicate_function_name(); 
#else
    return 0;
#endif
}
