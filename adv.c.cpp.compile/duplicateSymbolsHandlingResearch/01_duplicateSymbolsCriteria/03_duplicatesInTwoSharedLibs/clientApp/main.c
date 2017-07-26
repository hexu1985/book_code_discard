#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = 0;
    nRetValue += shlibfirst_function(1);
    nRetValue += shlibsecond_function(2);
    nRetValue += shlib_duplicate_function(3);
    return nRetValue;
}
