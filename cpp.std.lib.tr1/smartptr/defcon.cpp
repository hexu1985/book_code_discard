#include <tr1/memory>
#include "sputil.h"

using std::tr1::shared_ptr;

int main()
{
    shared_ptr<int> sp;
    show("default constructor", sp);

    return 0;
}
