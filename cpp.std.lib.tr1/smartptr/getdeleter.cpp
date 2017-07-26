#include <tr1/memory>
#include <iostream>

using std::tr1::shared_ptr;
using std::tr1::get_deleter;
using std::cout;

struct del
{
    void operator ()(void *ptr)
    {
        delete ptr;
    }
};

int main()
{
    shared_ptr<int> sp0(new int);
    shared_ptr<int> sp1(new int, del());
    cout << get_deleter<del>(sp0) << '\n';
    cout << get_deleter<del>(sp1) << '\n';

    return 0;
}

