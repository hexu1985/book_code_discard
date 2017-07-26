#include <tr1/memory>
#include "sputil.h"

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;

int main()
{
    shared_ptr<resource> sp(new resource(4));

    weak_ptr<resource> wp0(sp);
    weak_ptr<resource> wp1(wp0);

    show("first weak_ptr", wp0);
    show("second weak_ptr", wp1);

    return 0;
}
