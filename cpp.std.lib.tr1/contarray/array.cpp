#include <algorithm>
#include <iostream>
#include <tr1/array>

using std::cout;
using std::sort;
using std::tr1::array;

template <class Container>
void do_sort(Container &values)
{
    sort(values.begin(), values.end());
}

int main()
{
    const int ELEMS = 6;
    array<int, ELEMS> values = {3, 1, 4, 2, 9, 8};
    for (int i = 0; i < ELEMS; ++i)
        cout << values[i] << ' ';
    cout << '\n';
    do_sort(values);
    for (int i = 0; i < ELEMS; ++i)
        cout << values[i] << ' ';
    cout << '\n';

    return 0;
}
