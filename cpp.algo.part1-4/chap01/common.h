#ifndef __common_h
#define __common_h

#include <iostream>

static
void print(int *id, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << id[i] << " ";
    std::cout << '\n';
}

#endif
