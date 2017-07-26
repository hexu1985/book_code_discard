#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlibsecond_function();
    shlib_function();
    return 0;
}
