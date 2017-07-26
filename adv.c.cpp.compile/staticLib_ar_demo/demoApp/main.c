#include <stdio.h>
#include "mystaticlibexports.h"

int main(int argc, char* argv[])
{
    int nRetValue = 0;
    nRetValue += first_function(1);
    nRetValue += second_function(2);
    nRetValue += third_function(3);
    nRetValue += fourth_function(4);
    printf("The result is %d\n", nRetValue);
    return nRetValue;
}
