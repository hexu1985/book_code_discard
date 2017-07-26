#include <algorithm>
#include <iostream>
#include <tr1/array>
#include <iterator>

using std::cout;
using std::sort;
using std::tr1::array;
using std::copy;
using std::ostream_iterator;

int main()
{
    const int ELEMS = 6;
    array<int, ELEMS> values = {3, 1, 4, 2, 9, 8};
    copy(values.begin(), values.end(),
        ostream_iterator<int>(cout, " "));
    cout << '\n';
    sort(values.begin(), values.end());
    copy(values.begin(), values.end(),
        ostream_iterator<int>(cout, " "));
    cout << '\n';

    return 0;
}
