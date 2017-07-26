#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlib_function();    // duplicate ABI function
    shlibfirst_function();
    shlibsecond_function();
    shlibsecond_another_function(); // this one internally calls shlib_function()
    return 0;
}
