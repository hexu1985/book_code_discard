#include <tr1/memory>

#include "sputil.h"

using std::tr1::weak_ptr;

int main()
{
    weak_ptr<int> sp;
    show("default constructor", sp);

    return 0;
}

