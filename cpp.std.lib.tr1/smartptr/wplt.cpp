#include <algorithm>
#include <tr1/memory>
#include <iostream>
#include <set>

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;
using std::lower_bound;
using std::set;
using std::cout;

typedef shared_ptr<int> spi;
typedef weak_ptr<int> wpi;
typedef set<wpi> iset;
typedef iset::const_iterator citer;

static void lookup(const iset &data, wpi wp)
{
    citer res = lower_bound(data.begin(), data.end(), wp);
    spi sp0(wp);
    cout << *sp0;
    if (res == data.end() || spi(*res) != sp0)
        cout << " not found\n";
    else
        cout << " found\n";
}

int main()
{
    iset data;

    spi sp0(new int(0));
    spi sp1(new int(1));
    spi sp2(new int(2));
    spi sp3(sp1);
    spi sp4(new int(1));

    data.insert(wpi(sp0));
    data.insert(wpi(sp1));
    data.insert(wpi(sp2));
    lookup(data, wpi(sp1));
    lookup(data, wpi(sp3));
    lookup(data, wpi(sp4));

    return 0;
}
