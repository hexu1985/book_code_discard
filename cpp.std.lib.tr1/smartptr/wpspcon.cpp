#include <tr1/memory>

#include "sputil.h"

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;

int main()
{
    shared_ptr<resource> sp(new resource(4));

    show("shared_ptr", sp);
    weak_ptr<resource> wp(sp);
    show("weak_ptr", wp);

    return 0;
}
