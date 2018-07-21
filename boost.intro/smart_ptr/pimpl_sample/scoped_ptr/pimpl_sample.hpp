// pimpl_sample.hpp
#if !defined (PIMPL_SAMPLE)
#define PIMPL_SAMPLE

#include "boost/scoped_ptr.hpp"

class pimpl_sample {
    struct impl; // 译者注：原文中这句在class 之外，应有误
    boost::scoped_ptr<impl> pimpl_;

public:
    pimpl_sample();
    ~pimpl_sample();
    void do_something();
};

#endif
