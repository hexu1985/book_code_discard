#include <stdio.h>
#include "shlibexports.h"

extern int nShlibVariable;

int main(int argc, char* argv[])
{
    int nRetValue = shlib_function();
    nRetValue    += nShlibVariable;

    // purposefully calling second time
    nRetValue    += shlib_function();
    nRetValue    += nShlibVariable;
   
    return nRetValue;
}

