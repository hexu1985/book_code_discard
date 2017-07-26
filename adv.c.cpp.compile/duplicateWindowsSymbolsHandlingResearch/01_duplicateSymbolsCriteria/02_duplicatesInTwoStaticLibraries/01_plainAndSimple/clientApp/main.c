#include <stdio.h>
#include "staticlibfirstexports.h"
#include "staticlibsecondexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = 0;
    nRetValue += staticlibfirst_function(1);
    nRetValue += staticlibsecond_function(2);
    nRetValue += staticlib_duplicate_function(3);
    printf("nRetValue = %d\n", nRetValue);
    return nRetValue;
}
