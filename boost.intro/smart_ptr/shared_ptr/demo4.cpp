#include "boost/shared_ptr.hpp"
#include <iostream>

class A {
  class deleter {
    public:
      void operator()(A* p) {
        std::cout << "delete p" << std::endl;
        delete p;
      }
  };
  friend class deleter;
public:

  virtual void sing() {
    std::cout << "Lalalalalalalalalalala" << std::endl;
  }

  static boost::shared_ptr<A> createA() {
    boost::shared_ptr<A> p(new A(),A::deleter());
    return p;
  }

protected:
  virtual ~A() {};
};

int main() {
  boost::shared_ptr<A> p=A::createA();
  p->sing();
}

