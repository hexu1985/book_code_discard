#include <tr1/memory>
#include <iostream>

using std::tr1::shared_ptr;
using std::cout;

int main()
{
    shared_ptr<int> sp(new int);
    cout << "   get: " << sp.get() << '\n';
    cout << "object: " << sp << '\n';

    return 0;
}
