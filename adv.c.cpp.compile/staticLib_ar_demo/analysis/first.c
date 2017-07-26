#include <stdio.h>
#include "mystaticlibexports.h"

int first_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+1);
}
