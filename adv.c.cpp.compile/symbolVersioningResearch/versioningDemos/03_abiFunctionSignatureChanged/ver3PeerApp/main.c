#include <stdio.h>
#include "simple.h"

#define NORMALIZATION_FACTOR (1000)

int main(int argc, char* argv[])
{
    int nFirst  = first_function(1, NORMALIZATION_FACTOR);
    nFirst /= NORMALIZATION_FACTOR;
    int nSecond = second_function(2);
    int nFourth  = fourth_function(4);
    int nRetValue = nFirst + nSecond + nFourth;
    printf("first(1) + second(2) + fourth(4) = %d\n", nRetValue);
    return nRetValue;
}
