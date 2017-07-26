#include <stdio.h>
#include "staticlibexports.h"
#include "shlibexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = 0;
    nRetValue += staticlib_first_function(1);
    nRetValue += staticlib_second_function(2);

    shlib_function();    
    shared_static_duplicate_function(1);
    printf("nRetValue = %d\n", nRetValue);
    return nRetValue;
}
