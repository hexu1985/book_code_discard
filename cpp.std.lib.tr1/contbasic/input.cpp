#include <iostream>
using std::cout;

template <class Iter>
Iter maximum(Iter first, Iter last)
{
    Iter res = first++;

    while (first != last)
    {
        if (*res < *first)
            res = first;
        ++first;
    }

    return res;
}

int main()
{
    const int NVALS = 6;
    int values[NVALS] = {3, 1, 9, 4, 5, 7};
    cout << "maximum: " 
        << *maximum(values, values + NVALS)
        << '\n';

    return 0;
}

