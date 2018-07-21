#include "boost/shared_ptr.hpp"
#include <cassert>

class A {
    boost::shared_ptr<int> no_;
public:
    A(boost::shared_ptr<int> no) : no_(no) {}
    void value(int i) {
        *no_=i;
    }
};

class B {
    boost::shared_ptr<int> no_;
public:
    B(boost::shared_ptr<int> no) : no_(no) {}
    int value() const {
        return *no_;
    }
};

int main() {
    boost::shared_ptr<int> temp(new int(14));
    A a(temp);
    B b(temp);
    a.value(28);
    assert(b.value()==28);
}
