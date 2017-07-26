#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlibsecond_function();
    shlibfirst_function();
    return 0;
}
