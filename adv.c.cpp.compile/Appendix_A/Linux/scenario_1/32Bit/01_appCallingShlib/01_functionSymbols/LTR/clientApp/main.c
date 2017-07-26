#include <stdio.h>
#include "shlibexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = shlib_function();
    // purposefully calling second time
    nRetValue    += shlib_function();
    return nRetValue;
}

