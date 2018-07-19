// pimpl_sample.hpp
#if !defined (PIMPL_SAMPLE)
#define PIMPL_SAMPLE

class pimpl_sample {
    struct impl; // 译者注：原文中这句在class 之外，应有误
    impl* pimpl_;

public:
    pimpl_sample();
    ~pimpl_sample();
    void do_something();
};

#endif
