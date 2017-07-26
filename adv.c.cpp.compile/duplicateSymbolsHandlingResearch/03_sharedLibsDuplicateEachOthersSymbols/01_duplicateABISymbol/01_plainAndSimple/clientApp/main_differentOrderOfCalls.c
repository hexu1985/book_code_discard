#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
	// Reverse order of calls - first shlibsecond methods
	// get called, followed by the shlibfirst methods
    shlibsecond_function();
    shlibsecond_another_function();
    shlib_function();    // duplicate ABI function
    shlibfirst_function();
    return 0;
}
