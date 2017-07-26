#include <stdio.h>
#include "shlibexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = shlib_function();
    
    // purposefully making another call
    // to the same function
    nRetValue    += shlib_function();
    return nRetValue;
}

