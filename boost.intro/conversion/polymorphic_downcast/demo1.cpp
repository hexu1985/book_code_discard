#include <iostream>
#include "boost/cast.hpp"

struct base {
  virtual ~base() {};
};

struct derived1 : public base {
  void foo() {
    std::cout << "derived1::foo()\n";
  }
};

struct derived2 : public base {
  void foo() {
    std::cout << "derived2::foo()\n";
  }
};

void older(base* p) {
  // Logic that suggests that p points to derived1 omitted
  derived1* pd=static_cast<derived1*>(p);
  pd->foo(); // <-- What will happen here?
}

void newer(base* p) {
  // Logic that suggests that p points to derived1 omitted
  derived1* pd=boost::polymorphic_downcast<derived1*>(p);
  // ^-- The above cast will cause an assertion in debug builds
  pd->foo();
}

int main() {
       derived2* p=new derived2;
       older(p); // <-- Undefined
       newer(p); // <-- Well defined in debug build
}

