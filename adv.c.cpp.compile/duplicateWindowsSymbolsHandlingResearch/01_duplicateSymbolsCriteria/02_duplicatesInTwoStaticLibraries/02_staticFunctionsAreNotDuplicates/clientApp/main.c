#include <stdio.h>
#include "staticlibfirstexports.h"
#include "staticlibsecondexports.h"

int main(int argc, char* argv[])
{
    staticlibfirst_function(1);
    staticlibsecond_function(2);
    return 0;
}
