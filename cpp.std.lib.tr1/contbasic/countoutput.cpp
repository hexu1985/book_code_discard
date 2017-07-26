#include <iostream>
using std::cout;

template <class Iter>
Iter setcount(Iter first, int count)
{
    for (int i = 0; i < count; ++i)
        *first++ = i;
}

int main()
{
    const int NVALS = 6;
    int values[NVALS];
    setcount(values, NVALS);
    for (int i = 0; i < NVALS; ++i)
        cout << values[i] << ' ';
    cout << '\n';

    return 0;
}

