#include <stdio.h>
#include "shlibexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = shlib_function();
    printf("nRetValue = %d\n", nRetValue);
    return nRetValue;
}
