#include <algorithm>
#include <functional>
#include <iostream>

using std::for_each;
using std::unary_function;
using std::cout;

template <class Ty>
struct writer: unary_function<Ty, void>
{
    void operator ()(const Ty &val)
    {
        cout << val << ' ';
    }
};

int main()
{
    const int NVALS = 6;
    int values[NVALS] = {3, 1, 9, 4, 5, 7};
    for_each(values, values + NVALS, writer<int>());

    return 0;
}

