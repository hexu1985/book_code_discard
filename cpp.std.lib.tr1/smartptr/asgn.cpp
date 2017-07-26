#include <tr1/memory>
#include <iostream>

#include "sputil.h"

using std::tr1::shared_ptr;
using std::auto_ptr;

typedef shared_ptr<resource> sps;
typedef auto_ptr<resource> aps;

static void asgn0()
{
    sps sp0(new resource(1));
    show("construct sp0", sp0);

    sps sp1(new resource(2));
    show("construct sp1", sp1);

    sp1 = sp0;

    show("assign, sp0", sp0);
    show("assign, sp1", sp1);
}

static void asgn1()
{
    sps sp2(new resource(3));
    show("construct sp2", sp2);

    aps ap0(new resource(2));
    show("construct ap0", ap0);

    sp2 = ap0;

    show("assign, ap0", ap0);
    show("assign, sp2", sp2);
}

int main()
{
    asgn0();
    asgn1();

    return 0;
}
