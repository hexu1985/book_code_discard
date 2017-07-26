#include <tr1/array>
#include <iostream>
#include <stdexcept>

using std::tr1::array;
using std::cin;
using std::cout;
using std::out_of_range;

const int ELEMS = 10;
array<int, ELEMS> squares =
    {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int main()
{
    int idx = -1;
    for ( ; ; ) {
        try
        {
            cout << idx << " squared is "
                << squares.at(idx) << '\n';
        }
        catch (const out_of_range &)
        {
            cout << "Value to square: ";
            cin >> idx;
        }
    }

    return 0;
}
