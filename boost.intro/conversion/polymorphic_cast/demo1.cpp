#include <iostream>
#include <string>
#include "boost/cast.hpp"

class base1 {
public:
  virtual void print() {
    std::cout << "base1::print()\n";
  }

  virtual ~base1() {}
};

class base2 {
public:

  void only_base2() {
    std::cout << "only_base2()\n";
  }

  virtual ~base2() {}
};

class derived : public base1, public base2 {
public:

  void print() {
    std::cout << "derived::print()\n";
  }

  void only_here() {
    std::cout << "derived::only_here()\n";
  }
  void only_base2() {
    std::cout << "Oops, here too!\n";
  }
};

int main() {
  base1* p1=new derived;

 p1->print();

  try {
    derived* pD=boost::polymorphic_cast<derived*>(p1);
    pD->only_here();
    pD->only_base2();

    base2* pB=boost::polymorphic_cast<base2*>(p1);
    pB->only_base2();

  }
  catch(std::bad_cast& e) {
    std::cout << e.what() << '\n';
  }

  delete p1;
}

