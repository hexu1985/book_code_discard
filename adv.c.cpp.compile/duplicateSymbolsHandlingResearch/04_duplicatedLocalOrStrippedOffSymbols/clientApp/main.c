#include <stdio.h>
#include "staticlibexports.h"
#include "shlibexports.h"

static int local_function(int x)
{
    printf("clientApp: %s\n", __FUNCTION__);
    return 0;	
}

static int local_function_strippedoff(int x)
{
    printf("clientApp: %s\n", __FUNCTION__);
    return 0;		
}

int main(int argc, char* argv[])
{
    shlib_function();
    staticlib_function(1);
    local_function(1);
    local_function_strippedoff(1);
    return 0;
}
