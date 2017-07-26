#include <stdio.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

using namespace shlibfirst;
using namespace shlibsecond;

int main(int argc, char* argv[])
{
    shlibfirst_function();
    shlibsecond_function();
    return 0;
}
