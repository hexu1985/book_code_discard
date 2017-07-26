#include <tr1/array>
#include <stdlib.h>
#include <iostream>

using std::tr1::array;
using std::cout;

int lt(const void *left, const void *right)
{
    int il = *(int *) left;
    int ir = *(int *) right;
    return il < ir ? -1 : il == ir ? 0 : 1;
}

const int ELEMS = 6;

int main()
{
    array<int, ELEMS> values = {3, 1, 4, 2, 9, 8};
    for (int i = 0; i < ELEMS; ++i)
        cout << values[i] << ' ';
    cout << '\n';
    qsort(values.data(), ELEMS, sizeof(int), lt);
    for (int i = 0; i < ELEMS; ++i)
        cout << values[i] << ' ';
    cout << '\n';

    return 0;
}
