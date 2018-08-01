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

void polymorphic_cast_example(base1* p) {
  derived* pD=boost::polymorphic_cast<derived*>(p);
  pD->print();

  base2* pB=boost::polymorphic_cast<base2*>(p);
  pB->only_base2();
}

void dynamic_cast_example(base1* p) {
  derived* pD=dynamic_cast<derived*>(p);
  if (!pD)
    throw std::bad_cast();
  pD->print();

  base2* pB=dynamic_cast<base2*>(p);
  if (!pB)
    throw std::bad_cast();

  pB->only_base2();

}

int main() {
  base1* p=new derived;
  try {
    polymorphic_cast_example(p);
    dynamic_cast_example(p);
  }
  catch(std::bad_cast& e) {
    std::cout << e.what() << '\n';
  }
  delete p;
}

